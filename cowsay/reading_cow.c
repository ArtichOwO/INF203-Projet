#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>
#include <usage.h>

#define ARGC 2
Usage options[ARGC] = {
    { "-h", "", "Show this help", false, true, true },
    { "", "FILE", "Input file (defaults to stdin)", true, false, true },
};

const char * description = "File-eater `cowsay'";

void print_msg_end(int x, char c) {
    gotoxy(1, x);
    printf("__");
    gotoxy(2, x);
    printf("%c >", c);
    gotoxy(3, x);
    printf("--\n");
}

int main(int argc, char *const argv[]) {
    int c;
    while ((c = getopt(argc, argv, "h")) != -1)
        switch (c) {
            case 'h':
                usage(options, ARGC, argv[0], description);
                exit(EXIT_SUCCESS);
            default:
                usage(options, ARGC, argv[0], description);
                exit(EXIT_FAILURE);
        }

    bool is_stdin = argc == 1;
    
    FILE * input_file;

    if (is_stdin) {
        input_file = stdin;
    } else {
        input_file = fopen(argv[argc-1], "r");
    }

    if (input_file == NULL) {
        printf("Cannot open file %s\n", argv[0]);
        exit(-1);
    }

    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 500 * 1000000
    };

    update();
    print_msg(0, NULL, 0);
    show_cow("oo", " ");

    char letter = ' ';
    char tongue[] = { ' ', '\0' };

    for (int i = 2; !feof(input_file); i++) {
        print_msg_end(i, letter);

        gotoxy(9, 0);
        if (is_stdin)
            printf("\33[2K\rYour input (CTRL+D to exit): ");
        letter = fgetc(input_file);
        printf("\33[2K\r");
        letter = letter == '\n' ? ' ' : letter; 
        tongue[0] = letter == EOF ? 'U' : letter;
        gotoxy(4, 0);
        show_cow("oo", tongue);
        gotoxy(1, 0);

        fflush(stdout);
        nanosleep(&ts, &ts);
    }

    gotoxy(9, 0);
    fclose(input_file);

    return 0;
}
