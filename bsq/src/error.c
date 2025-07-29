Here are the contents for the file /bsq/bsq/src/error.c:

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void handle_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <map_file>\n", program_name);
    exit(EXIT_FAILURE);
}