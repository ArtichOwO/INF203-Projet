#ifndef USAGE_H
#define USAGE_H

#include <stdbool.h>

typedef struct {
	char * key;
	char * arg;
	char * description;
	bool no_key;
	bool no_arg;
	bool optional;
} Usage;

void usage(Usage * options, int argc, char * program, const char * description);

#endif // USAGE_H
