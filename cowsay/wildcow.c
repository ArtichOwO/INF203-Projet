#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>
#include <usage.h>

#define ARGC 5
Usage options[ARGC] = {
    { "-r", "", "Running cow", false, true, true },
    { "-T", "LENGTH", "Make the cow's tail grow", false, false, true },
    { "-e", "", "oO", false, true, true },
    { "-h", "", "Show this help", false, true, true },
    { "", "INPUT", "Input text to say", true, false, false },
};

const char * description = "Animated `cowsay'";

void a_run() {
    const char * anim[] = {
        "            /|----w /   \n"
        "            |\\     \\|   \n",

        "            /\\----w /   \n"
        "           /  \\    / \\   \n",

        "            /|----w /|  \n"
        "           |  \\    | \\   \n",

        "            \\/----w |   \n"
        "            /|     /\\   \n",

        "            /\\----w /   \n"
        "           /  \\    / \\   \n"
    };

    size_t anim_len = sizeof(anim) / sizeof(char *);
    int i = 0;

    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 250 * 1000000
    };

    while (true) {
        if (i == anim_len) i = 0;

        gotoxy(7, 0);
        printf("%s", anim[i++]);
        nanosleep(&ts, &ts);
    }
}

void a_tail(int length) {
    gotoxy(6, 22);

    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 500 * 1000000
    };

    for (int i = 0; i < length;i++) {
        printf(i%2 == 0 ? "\\" : "/");
        fflush(stdout);
        nanosleep(&ts, &ts);
    }

    gotoxy(9, 0);
}

void a_eyes() {
    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 500 * 1000000
    };
    
    for (int i = 0;;i++) {
        gotoxy(5, 10);
        printf(i%2 == 0 ? "Oo" : "oO");
        fflush(stdout);
        nanosleep(&ts, &ts);
    }

    gotoxy(9, 0);
}

int main(int argc, char *const argv[]) {
    int c;

    enum {
        A_RUN, A_TAIL, A_EYES
    } animation = A_RUN;

    int A_TAIL_length = 0;

    while ((c = getopt(argc, argv, "rT:eh")) != -1)
        switch (c) {
            case 'r':
                animation = A_RUN;
                break; 
            case 'T':
                animation = A_TAIL;
                A_TAIL_length = atoi(optarg);
                break;
            case 'e':
                animation = A_EYES;
                break;
            case 'h':
                usage(options, ARGC, argv[0], description);
                exit(EXIT_SUCCESS);
            default:
                usage(options, ARGC, argv[0], description);
                exit(EXIT_FAILURE);
        }

    update();

    print_msg(argc, argv, optind);
    show_cow("oo", " ");

    switch (animation) {
        case A_RUN:
            a_run();
            break;
        case A_TAIL:
            a_tail(A_TAIL_length);
            break;
        case A_EYES:
            a_eyes();
            break;
    }

    return 0;
}
