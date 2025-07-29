// This file declares the functions and types used in solve.c, providing an interface for solving the problem.

#ifndef SOLVE_H
#define SOLVE_H

// Function to find the largest square in the map
int find_largest_square(char **map, int rows, int cols);

// Function to mark the largest square in the map
void mark_largest_square(char **map, int rows, int cols, int size, int x, int y);

#endif // SOLVE_H