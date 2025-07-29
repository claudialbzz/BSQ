// This file declares the functions used in print.c, allowing other files to print results.

#ifndef PRINT_H
#define PRINT_H

void print_map(char **map, int rows, int cols);
void print_result(int largest_square_size, int x, int y);

#endif // PRINT_H