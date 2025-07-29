#ifndef MAP_H
#define MAP_H

typedef struct {
    char **grid;
    int rows;
    int cols;
    char empty;
    char obst;
    char full;
} t_map;

int parse_map(int fd, t_map *map);
void free_map(t_map *map);

#endif