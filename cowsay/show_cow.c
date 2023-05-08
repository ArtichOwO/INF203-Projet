#include <stdio.h>

#include <show_cow.h>

void show_cow(char * eyes, char * tongue) {
    const char * cow = 
        "    \\   ^__^\n"
        "     \\  (%s)\\_______\n"
        "        (__)\\       )\\/\\\n"
        "         %s  ||----w |\n"
        "            ||     ||\n";
    
    printf(cow, eyes, tongue);
}
