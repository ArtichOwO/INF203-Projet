#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>

void print_msg_end(int x, char c) {
    gotoxy(1, x);
    printf("__");
    gotoxy(2, x);
    printf("%c >", c);
    gotoxy(3, x);
    printf("--\n");
}

int main(int argc, char *const argv[]) {
    bool is_stdin = false;

    char c;
    while ((c = getopt(argc, argv, "i")) != -1)
        switch (c) {
            case 'i':
                is_stdin = true;
                break;
        }

    FILE * input_file;

    if (is_stdin) {
        printf("STDIN\n");
        input_file = stdin;
    } else {
        printf("%s\n", argv[argc-1]);
        input_file = fopen(argv[argc-1], "r");
    }

    if ( input_file == NULL ) {
        printf( "Cannot open file %s\n", argv[0] );
        exit( -1 );
    }

    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 500 * 1000000
    };
    
    update();
    print_msg(0, NULL, 0);

    char letter = ' ';
    char tongue[] = { ' ', '\0' };

    for (int i = 2; !feof(input_file); i++) {
        print_msg_end(i, letter);

        letter = fgetc(input_file);
        letter = letter == '\n' ? ' ' : letter; 
        tongue[0] = letter == EOF ? 'U' : letter;
        gotoxy(4, 0);
        show_cow("oo", tongue);
        gotoxy(1, 0);

        fflush(stdout);
        nanosleep(&ts, &ts);
    }

    gotoxy(9, 0);

    return 0;
}
