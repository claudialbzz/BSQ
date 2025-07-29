// This header file declares the functions and types used in map.c, allowing other files to interact with map-related functionality.

#ifndef MAP_H
#define MAP_H

// Function to load the map from a file
char **load_map(const char *filename, int *rows, int *cols);

// Function to validate the format of the map
int validate_map(char **map, int rows, int cols);

// Function to free the allocated memory for the map
void free_map(char **map, int rows);

#endif // MAP_H