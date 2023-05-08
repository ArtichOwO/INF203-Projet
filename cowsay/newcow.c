#include "usage.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef USE_PERL
#include <EXTERN.h>
#include <perl.h>
#endif

#include <print_msg.h>
#include <show_cow.h>

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

#define ARGC 11
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
    { "-h", "", "Show this help", false, true, true },
    { "", "INPUT", "Input text to say", true, false, false },
};

const char * description = "`cowsay' rewritten with less options lolwut";

int main(int argc, char *const argv[]) {
    char * eyes = E_BASIC;
    char * tongue = T_BASIC;

    int c;

    while ((c = getopt(argc, argv, "e:T:dgpstwyh")) != -1)
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
            case 'h':
                usage(options, ARGC, argv[0], description);
                exit(EXIT_SUCCESS);
            default:
                usage(options, ARGC, argv[0], description);
                exit(EXIT_FAILURE);
        }

    print_msg(argc, argv, optind);
    show_cow(eyes, tongue);

    return 0;
}
