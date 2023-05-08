#include <string.h>
#include <stdio.h>

#include <print_msg.h>

void print_msg(int argc, char *const argv[], int begin) {
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

inline void print_msg_str(char * msg) {
    print_msg(1, &msg, 0);
}
