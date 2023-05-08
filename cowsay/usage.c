#include <stdio.h>

#include <usage.h>

void usage(Usage * options, int argc, char * program, const char * description) {
    printf("Usage: %s ", program);
    for (int i = 0; i < argc; i++) {
        printf(options[i].optional ? "[" : ""); // Ex: [-a ARG]
        if (options[i].no_key) {
            printf("%s", options[i].arg); // Ex: ARG
        } else if (options[i].no_arg) {
            printf("%s", options[i].key); // Ex: -a
        } else {
            printf("%s %s", options[i].key, options[i].arg); // Ex: -a ARG
        }
        printf(options[i].optional ? "] " : " ");
    }

    printf("\n\n%s\n\n", description);

    /* Ex:  -a  ARG    Description de l'option a
     */
    for (int i = 0; i < argc; i++) {
        printf("\t%s\t%s\t%s\n",
            options[i].key, 
            options[i].arg, 
            options[i].description);
    }

    printf("\n\n");
}
