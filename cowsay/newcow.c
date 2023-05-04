#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <EXTERN.h>
#include <perl.h>

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

void affiche_message(int argc, char *const argv[], int begin) {
    int i;

    size_t msg_len = 0;
    for (i = begin; i < argc; i++)
        msg_len += strlen(argv[i]) + 1;

    printf(" _");
    for (i = 0; i < msg_len; i++)
        printf("_");
    printf("\n");

    printf("< ");
    for (i = begin; i < argc; i++)
        printf("%s ", argv[i]);
    printf(">\n");

    printf(" -");
    for (i = 0; i < msg_len; i++)
        printf("-");
    printf("\n");
}

void affiche_vache(char * eyes, char * tongue) {
    const char * cow = 
        "    \\   ^__^\n"
        "     \\  (%s)\\_______\n"
        "        (__)\\       )\\/\\\n"
        "         %s  ||----w |\n"
        "            ||     ||\n";
    
    printf(cow, eyes, tongue);
}

int main(int argc, char *const argv[]) {
    char * eyes = E_BASIC;
    char * tongue = T_BASIC;

    int c;

    while ((c = getopt(argc, argv, "e:T:dgpstwy")) != -1)
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
            default:
                exit(EXIT_FAILURE);
        }

    affiche_message(argc, argv, optind);
    affiche_vache(eyes, tongue);

    return 0;
}
