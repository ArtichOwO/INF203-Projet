#include "usage.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef USE_PERL
#include <EXTERN.h>
#include <perl.h>

static PerlInterpreter * my_perl;
#endif

#include <print_msg.h>
#include <show_cow.h>

/* Yeux et langues de base
 */
#define E_BASIC "oo"
#define E_DEAD "xx"
#define E_GREEDY "$$"
#define E_PARANO "@@"
#define E_STONED "**"
#define E_TIRED "--"
#define E_WIRED "OO"
#define E_YOUTH ".."

#define T_BASIC " "
#define T_OUT "U"

/* Documentation
 * cf. /include/usage.h
 */
#ifndef USE_PERL
#define ARGC 12
#else
#define ARGC 13
#endif

Usage options[ARGC] = {
    { "-e", "EYES", "Define eyes to use (use 2 chars)", false, false, true },
    { "-T", "TONGUE", "Define tongue to use (use 1 char)", false, false, true },
    { "-d", "", "Dead cow", false, true, true },
    { "-g", "", "Greedy cow", false, true, true },
    { "-p", "", "Paranoïd cow", false, true, true },
    { "-s", "", "Stoned cow", false, true, true },
    { "-t", "", "Tired cow", false, true, true },
    { "-w", "", "Wired cow", false, true, true },
    { "-y", "", "Young cow", false, true, true },
    { "-i", "", "Thinking cow", false, true, true },
    #ifdef USE_PERL
    { "-f", "COWFILE", "Use the given cowfile", false, false, true },
    #endif
    { "-h", "", "Show this help", false, true, true },
    { "", "INPUT", "Input text to say", true, false, false },
};

const char * description = "`cowsay' rewritten with less options lolwut";

int main(int argc, char *const argv[], char *const env[]) {
    char * eyes = E_BASIC;
    char * tongue = T_BASIC;

    bool think = false;

    #ifdef USE_PERL
    bool use_cowfile = false;
    char * my_argv[2];
    #endif

    // Parsing d'argument basique
    int c;
    while ((c = getopt(argc, argv, "e:T:dgpstwyif:h")) != -1)
        switch (c) {
            case 'e':
                eyes = optarg;
                break;
            case 'T':
                tongue = optarg;
                break;
            case 'd':
                eyes = E_DEAD;
                tongue = T_OUT;
                break;
            case 'g':
                eyes = E_GREEDY;
                break;
            case 'p':
                eyes = E_PARANO;
                break;
            case 's':
                eyes = E_STONED;
                tongue = T_OUT;
                break;
            case 't':
                eyes = E_TIRED;
                break;
            case 'w':
                eyes = E_WIRED;
                break;
            case 'y':
                eyes = E_YOUTH;
                break;
            case 'i':
                think = true;
                break;
            #ifdef USE_PERL
            case 'f':
                use_cowfile = true;
                my_argv[1] = optarg;
                break;
            #endif
            case 'h':
                usage(options, ARGC, argv[0], description);
                exit(EXIT_SUCCESS);
            default:
                usage(options, ARGC, argv[0], description);
                exit(EXIT_FAILURE);
        }

    #ifdef USE_PERL
    if (use_cowfile) {
        /* Initialisation de l'environnement Perl
         * avec en argument le cowfile à exécuter
         */
        PERL_SYS_INIT3(&argc, (char ***)&argv, (char ***)&env);
        my_perl = perl_alloc();
        perl_construct(my_perl);
        PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
        perl_parse(my_perl, NULL, 2, my_argv, (char **)NULL);

        /* Définitions des variables eyes, tongue et thoughts
         * pour le script Perl qui retournera the_cow
         */
        char * perl_eyes = malloc(14);
        sprintf(perl_eyes, "$eyes = \"%s\"", eyes);
        eval_pv(perl_eyes, TRUE);
        free(perl_eyes);

        char * perl_tongue = malloc(14);
        sprintf(perl_tongue, "$tongue = \"%s\"", tongue);
        eval_pv(perl_tongue, TRUE);
        free(perl_tongue);

        char * perl_msg_part;
        eval_pv("$thoughts = \"\"", TRUE);
        for (int i = optind; i < argc; i++) {
            perl_msg_part = malloc(24+strlen(argv[i]));
            sprintf(perl_msg_part, "$thoughts = \"${thoughts} %s\"", argv[i]);
            eval_pv(perl_msg_part, TRUE);
            free(perl_msg_part);
        }

        perl_run(my_perl);

        printf("%s", SvPV_nolen(get_sv("the_cow", 0)));

        // Termination de l'environnement
        perl_destruct(my_perl);
        perl_free(my_perl);
        PERL_SYS_TERM();
    } else {
    #endif

    // Impression de la vache
    if (!think) 
        print_msg(argc, argv, optind);
    else
        print_msg_think(argc, argv, optind);

    if (!think)
        show_cow(eyes, tongue);
    else
        show_cow_think(eyes, tongue);

    #ifdef USE_PERL
    }
    #endif

    return 0;
}
