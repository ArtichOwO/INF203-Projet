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
