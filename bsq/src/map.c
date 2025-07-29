#include <stdio.h>
#include <stdlib.h>
#include "map.h"

char **load_map(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    fscanf(file, "%d %d", rows, cols);
    char **map = malloc(*rows * sizeof(char *));
    for (int i = 0; i < *rows; i++) {
        map[i] = malloc((*cols + 1) * sizeof(char)); // +1 for null terminator
        fscanf(file, "%s", map[i]);
    }

    fclose(file);
    return map;
}

int validate_map(char **map, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (strlen(map[i]) != cols) {
            return 0; // Invalid map format
        }
    }
    return 1; // Valid map format
}

void free_map(char **map, int rows) {
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}