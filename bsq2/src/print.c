#include <unistd.h>
#include "../include/map.h"

void print_map(t_map *map)
{
    int i = 0;
    while (i < map->rows) {
        int j = 0;
        while (j < map->cols) {
            write(1, &map->grid[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}