
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "solve.h"
#include "print.h"
#include "error.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        print_error("Usage: ./bsq <map_file>");
        return EXIT_FAILURE;
    }

    char *map_file = argv[1];
    char **map = load_map(map_file);
    if (!map) {
        print_error("Failed to load map.");
        return EXIT_FAILURE;
    }

    int largest_square_size = find_largest_square(map);
    if (largest_square_size < 0) {
        print_error("Error while solving the map.");
        free(map);
        return EXIT_FAILURE;
    }

    print_map_with_square(map, largest_square_size);
    free(map);
    return EXIT_SUCCESS;
}