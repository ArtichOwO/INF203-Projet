# INF203 - Projet Cowsay
> Léo Grange, Arthur Lepley

Les sources sont disponibles à [cette adresse](https://github.com/ArtichOwO/INF203-Projet).

## Sommaire

- [Préliminaires](#préliminaires)
- [Bash](#bash)
  - [Kindergarten cow](#kindergarten-cow)
  - [Primary school cow](#primary-school-cow)
  - [Highscool cow](#highschool-cow)
  - [College cow](#college-cow)
  - [University cow](#university-cow)
  - [Smart cow](#smart-cow)
  - [Crazy cow](#crazy-cow)
- [C](#c)
  - [`newcow`](#newcow)
    - [`newcow.c`](#newcowc)
    - [`print_msg.c`](#print_msgc)
    - [`include/print_msg.h`](#includeprint_msgh)
    - [`show_cow.c`](#show_cowc)
    - [`include/show_cow.h`](#includeshow_cowh)
    - [`usage.c`](#usagec)
    - [`include/usage.h`](#includeusageh)
  - [`wildcow`](#wildcow)
    - [`wildcow.c`](#wildcowc)
    - [`include/animation.h`](#includeanimationh)
  - [`reading_cow`](#reading_cow)
    - [`reading_cow.c`](#reading_cowc)
  - [`tamagotchi_cow`](#tamagotchi_cow)
    - [`tamagotchi_cow.c`](#tamagotchi_cowc)
  - [`Makefile`](#makefile)

## Préliminaires

|Argument|Description|
|:-:|:-|
|`-n`|Désactiver le retour à la ligne automatique.|

```
$ figlet "AMIRITE?" | cowsay -n
________________________________________________
/     _    __  __ ___ ____  ___ _____ _____ ___  \
|    / \  |  \/  |_ _|  _ \|_ _|_   _| ____|__ \ |
|   / _ \ | |\/| || || |_) || |  | | |  _|   / / |
|  / ___ \| |  | || ||  _ < | |  | | | |___ |_|  |
| /_/   \_\_|  |_|___|_| \_\___| |_| |_____|(_)  |
\                                                /
------------------------------------------------
    \   ^__^
     \  (oo)\_______
        (__)\       )\/\
            ||----w |
            ||     ||
```

|Argument|Description|
|:-:|:-|
|`-W`|Définir la colonne à laquelle faire un retour à la ligne.|

```
$ cowsay -W 10 "CAPS LOCK IS CRUISE CONTROL FOR COOL"
 ___________
/ CAPS LOCK \
| IS CRUISE |
| CONTROL   |
\ FOR COOL  /
 -----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

|Argument|Description|Yeux|Langue|
|:-:|:-|:-:|:-:|
|`-b`|Vache robot.|`(==)`|Pas d'effet.|
|`-d`|Vache morte.|`(xx)`|`U`|
|`-g`|Vache avare.|`($$)`|Pas d'effet.|
|`-p`|Vache paranoïaque.|`(@@)`|Pas d'effet.|
|`-s`|Vache complètement défoncée.|`(**)`|`U`|
|`-t`|Vache fatiguée.|`(--)`|Pas d'effet.|
|`-w`|Vache en mode cablé.|`(OO)`|Pas d'effet.|
|`-y`|Vache rajeunie.|`(..)`|Pas d'effet.|

|Argument|Description|
|:-:|:-|
|`-e YEUX`|Définir de nouveaux yeux.|
|`-T LANGUE`|Définir une nouvelle langue.|

```
$ cowsay -e "♥♥" -T U "Let's All Love Lain"
 _____________________
< Let's All Love Lain >
 ---------------------
        \   ^__^
         \  (♥♥)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
```

|Argument|Description|
|:-:|:-|
|`-l`|Lister les cowfiles dans `$COWPATH`.|
|`-f FICHIER`|Choisir un cowfile différent.|

```
$ cowsay -f vader "DO NOT WANT"
 _____________
< DO NOT WANT >
 -------------
        \    ,-^-.
         \   !oYo!
          \ /./=\.\______
               ##        )\/\
                ||-----w||
                ||      ||

               Cowth Vader
```

## Bash

### Kindergarten cow

```bash
#!/bin/bash

for i in $(seq 1 10); do
    clear
    cowsay -y $i
    sleep 1
done
```

### Primary school cow

```bash
#!/bin/bash

for i in $(seq 1 $1); do
    clear
    cowsay -y $i
    sleep 1
done
```

### Highscool cow

```bash
#!/bin/bash

for i in $(seq 1 $1); do
    clear
    cowsay -y $(echo $i^2 | bc)
    sleep 1
done
```

### College cow

```bash
#!/bin/bash

a=0
b=1

for i in $(seq 0 $1); do
    clear
    cowsay " $a "
    c=$(expr $a + $b)
    a=$b
    b=$c
    sleep 1
done
```

### University cow

```bash
#!/bin/bash

for i in $(seq 2 $1); do
    n=$(factor $i | awk 'NF==2{print $2}')
    if [ "$n" != "" ]; then
        clear
        cowsay -b $n
        sleep 1
    fi
done
```

### Smart cow

```bash
#!/bin/bash

cowsay -e $(printf "%02i" $(echo "$1" | bc)) "$1"
```

### Crazy cow

```bash
#!/bin/bash

lookandsay() {
    n=$1

    [ $n -eq 1 ] && echo 1
    [ $n -eq 2 ] && echo 11

    s=11

    for i in $(seq 3 $(expr $n + 1)); do
        s+="#"
        l=$(expr $(echo $s | wc -c) - 1)

        cnt=1
        tmp=""

        for j in $(seq 1 $(expr $l - 1)); do
            sjm1=${s:$(expr $j - 1):1}

            if [ ${s:$j:1} != $sjm1 ]; then
                tmp+="$cnt$sjm1"
                cnt=1
            else
                cnt=$(expr $cnt + 1)
            fi
        done

        s=$tmp
    done

    echo $s
}

sequence=1
for i in $(seq 2 $1); do sequence+=" $(lookandsay $i)"; done

cowsay -e "°°" "Look-and-say: $sequence!"
```

## C

Les fichiers se trouvent dans le dossier [/cowsay/](https://github.com/ArtichOwO/INF203-Projet/tree/master/cowsay).

**Makefile**

### `newcow`

#### `newcow.c`
```c
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
```

#### `print_msg.c`
```c
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
```

#### `include/print_msg.h`
```c
#ifndef PRINT_MSG_H
#define PRINT_MSG_H

void print_msg(int argc, char *const argv[], int begin);
void print_msg_think(int argc, char *const argv[], int begin);
void print_msg_str(char * msg);

#endif // PRINT_MSG_H
```

#### `show_cow.c`
```c
#include <stdio.h>

#include <show_cow.h>

void show_cow_char(char * eyes, char * tongue, char lines) {
    const char * cow = 
        "    %c   ^__^\n"
        "     %c  (%s)\\_______\n"
        "        (__)\\       )\\/\\\n"
        "         %s  ||----w |\n"
        "            ||     ||\n";
    
    printf(cow, lines, lines, eyes, tongue);
}

inline void show_cow(char * eyes, char * tongue) {
    show_cow_char(eyes, tongue, '\\');
}

inline void show_cow_think(char * eyes, char * tongue) {
    show_cow_char(eyes, tongue, 'o');
}
```

#### `include/show_cow.h`
```c
#ifndef SHOW_COW_H
#define SHOW_COW_H

void show_cow(char * eyes, char * tongue);
void show_cow_think(char * eyes, char * tongue);

#endif // SHOW_COW_H
```

#### `usage.c`
```c
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
```

#### `include/usage.h`
```c
#ifndef USAGE_H
#define USAGE_H

#include <stdbool.h>

typedef struct {
    char * key; // -a
    char * arg; // ARG
    char * description; // Description de l'option a
    bool no_key; // ARG
    bool no_arg; // -a
    bool optional; // [-a ARG]
} Usage;

void usage(Usage * options, int argc, char * program, const char * description);

#endif // USAGE_H
```

### `wildcow`

#### `wildcow.c`
```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>
#include <usage.h>

/* Documentation
 * cf. /include/usage.h
 */
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
    // Les différentes frames
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

    // Voir https://stackoverflow.com/a/1157217
    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 200 * 1000000 // 200ms en ns
    };

    while (true) {
        // "Rembobiner" les frames
        if (i == anim_len) i = 0;
        // Bouger le curseur pour réimprimer les jambes
        gotoxy(7, 0);
        printf("%s", anim[i++]);
        nanosleep(&ts, &ts);
    }
}

void a_tail(int length) {
    // Bouger le curseur au niveau de la queue
    gotoxy(6, 22);

    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 500 * 1000000
    };

    for (int i = 0; i < length;i++) {
        printf(i%2 == 0 ? "\\" : "/");
        fflush(stdout); // Voir https://stackoverflow.com/a/338295
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
        // Bouger le curseur au niveau des yeux
        gotoxy(5, 10);
        printf(i%2 == 0 ? "Oo" : "oO");
        fflush(stdout);
        nanosleep(&ts, &ts);
    }
}

int main(int argc, char *const argv[]) {
    int c;

    enum {
        A_RUN, A_TAIL, A_EYES
    } animation = A_RUN;

    int A_TAIL_length = 0;

    // Parsing d'argument basique
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

    // cf. /include/animation.h
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
```

#### `include/animation.h`
```c
#ifndef ANIMATION_H
#define ANIMATION_H

// Macros pour réduire le nombre d'appels
#define update() printf("\033[H\033[J")
#define gotoxy(X, Y) printf("\033[%d;%dH", X, Y)

#endif // ANIMATION_H
```

### `reading_cow`

#### `reading_cow.c`
```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>
#include <usage.h>

/* Documentation
 * cf. /include/usage.h
 */
#define ARGC 2
Usage options[ARGC] = {
    { "-h", "", "Show this help", false, true, true },
    { "", "FILE", "Input file (defaults to stdin)", true, false, true },
};

const char * description = "File-eater `cowsay'";

void print_msg_end(int x, char c) {
    /* Imprime la fin du texte
     * __
     * c >
     * --
     * ^
     * x
     */
    gotoxy(1, x);
    printf("__");
    gotoxy(2, x);
    printf("%c >", c);
    gotoxy(3, x);
    printf("--\n");
}

int main(int argc, char *const argv[]) {
    int c;
    // Parsing d'argument basique
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
    print_msg(0, NULL, 0); // Message vide
    show_cow("oo", " ");

    char letter = ' ';
    /* String sous forme de tableau
     * pour lui éviter d'être copié en .rodata
     * et donc éviter les segfaults
     */
    char tongue[] = { ' ', '\0' };

    for (int i = 2; !feof(input_file); i++) {
        print_msg_end(i, letter);

        gotoxy(9, 0);
        if (is_stdin)
            printf("\33[2K\rYour input (Enter to confirm, CTRL+D to exit): ");
        letter = fgetc(input_file);
        printf("\33[2K\r"); // Effacer la ligne d'input
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
```

### `tamagotchi_cow`

#### `tamagotchi_cow.c`
```c
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include <print_msg.h>
#include <show_cow.h>
#include <animation.h>

// Yeux dans différents états
#define E_LIFEROCKS "^^"
#define E_LIFESUCKS "@@"
#define E_BYEBYELIFE "xx"

// Langue dans différents états
#define T_LIFEROCKS " "
#define T_LIFESUCKS " "
#define T_BYEBYELIFE "U"

// Impression de la vache dans différents états
void show_cow_state(int fitness) {
    if (4 <= fitness && fitness <= 6) {
        show_cow(E_LIFEROCKS, T_LIFEROCKS);
    } else if ((1 <= fitness && fitness <= 3) 
            || (7 <= fitness && fitness <= 9)) {
        show_cow(E_LIFESUCKS, T_LIFESUCKS);
    } else {
        show_cow(E_BYEBYELIFE, T_BYEBYELIFE);
    }
}

// Mettre à jour le stock de nourriture
void stock_update(int * stock, int lunchfood) {
    int crop = rand()%6 - 3;
    *stock -= lunchfood - crop;
    if (*stock < 0)
        *stock = 0;
}

// Mettre à jour la santé de la vache
void fitness_update(int * fitness, int lunchfood) {
    int digestion = rand()%3;
    *fitness += lunchfood - digestion;
}

int main(int argc, char const *argv[]) {
    unsigned int lunchfood;
    unsigned int ctime;
    int stock = 5;
    int fitness = 5;
    char * time_msg = malloc(17);

    time_t t;
    srand ((unsigned)time(&t));

    for (ctime = 0; 0 < fitness && fitness < 10; ctime++) {
        update();
        sprintf(time_msg, "Time: %i", ctime);
        print_msg_str(time_msg);
        show_cow_state(fitness);

        printf("Current stock: %i\n"
               "Give how much food: ", stock);
        /* `lunchfood` pourrait être
         * plus élevé que `stock`
         * mais ça n'a pas d'importance
         * puisque `stock_update` remet à zéro
         * `stock` si elle est négative
         */
        scanf("%i", &lunchfood);

        stock_update(&stock, lunchfood);
        fitness_update(&fitness, lunchfood);
    }

    update();
    sprintf(time_msg, "Score = %i", ctime);
    print_msg_str(time_msg);
    show_cow_state(fitness);

    return 0;
}
```

### `Makefile`

```makefile
OUTPUT_DIR = dist
CC = gcc
LD = ld

# Modifiable via la ligne de commande (USE_PERL=...)
USE_PERL ?= 1

CCFLAGS = -I include
LDFLAGS = 

# Si compilation sous MacOS
ifeq ($(shell uname -s),Darwin)
    LDFLAGS += -L$(shell xcode-select -p)/SDKs/MacOSX.sdk/usr/lib -lSystem
else
    LD = gcc
endif

# Si compilation avec Perl
ifeq ($(USE_PERL), 1)
    LIBPERL_PATH = $(shell perl -MConfig -e 'print $$Config{archlib}')
    CCFLAGS += -D_GNU_SOURCE -DUSE_PERL -I$(LIBPERL_PATH)/CORE
    LDFLAGS += -L$(LIBPERL_PATH)/CORE -lperl
endif

objs = $(addprefix $(OUTPUT_DIR)/, \
    print_msg.o \
    show_cow.o \
    usage.o \
)

.PHONY: all clean

all: newcow.exe wildcow.exe reading_cow.exe tamagotchi_cow.exe

clean:
    @rm -rf cowsay/dist
    @echo CLEAN

$(OUTPUT_DIR)/%.o: %.c
    @mkdir -p $(dir $@)
    @echo CC $@
    @$(CC) -c $^ -o $@ $(CCFLAGS)

%.exe: $(OUTPUT_DIR)/%.o $(objs)
    @echo LD $@
    @$(LD) $^ -o $(OUTPUT_DIR)/$@ $(LDFLAGS)
```
