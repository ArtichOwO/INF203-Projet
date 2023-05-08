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
