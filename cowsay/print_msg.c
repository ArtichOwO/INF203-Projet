#include <string.h>
#include <stdio.h>

#include <print_msg.h>

void print_msg_chr(int argc, char *const argv[], int begin, 
                   char top, char bot, char left, char right) {
    int i;

    // Taille totale du texte
    size_t msg_len = 0;
    for (i = begin; i < argc; i++)
        msg_len += strlen(argv[i]) + 1;

    // Dessus
    printf(" %c", top);
    for (i = 0; i < msg_len; i++)
        printf("%c", top);
    printf("\n");

    /* Impression des strings dans `argv` 
     * de `begin` à `argc`
     */
    printf("%c ", left);
    for (i = begin; i < argc; i++)
        printf("%s ", argv[i]);
    printf("%c\n", right);

    // Dessous
    printf(" %c", bot);
    for (i = 0; i < msg_len; i++)
        printf("%c", bot);
    printf("\n");
}

void print_msg(int argc, char *const argv[], int begin) {
    print_msg_chr(argc, argv, begin, '_', '-', '<', '>');
}

void print_msg_think(int argc, char *const argv[], int begin) {
    print_msg_chr(argc, argv, begin, '_', '-', '(', ')');
}

inline void print_msg_str(char * msg) {
    print_msg(1, &msg, 0);
}
