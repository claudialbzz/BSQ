#include "../include/bsq.h"

static int read_line(int fd, char *buf)
{
	int i = 0;
	while (read(fd, buf + i, 1) && buf[i] != '\n')
		i++;
	buf[i] = 0;
	return i;
}

static int parse_first_line(int fd, t_map *map)
{
	char buf[32];
	int len = read_line(fd, buf);
	if (len < 4) 
		return 0;

	int i = 0;
	while (buf[i] >= '0' && buf[i] <= '9') {
		map->rows = map->rows * 10 + (buf[i] - '0');
		i++;
	}
	map->empty = buf[len-3];
	map->obst = buf[len-2];
	map->full = buf[len-1];
	return (map->rows > 0 && map->empty != map->obst && 
			map->obst != map->full && map->empty != map->full);
}

int parse_map(int fd, t_map *map)
{
	if (!parse_first_line(fd, map)) return 0;

	char buf[1024];
	int len = read_line(fd, buf);
	if (len <= 0)
		return 0;

	map->cols = len;
	map->grid = malloc(map->rows * sizeof(char *));
	map->grid[0] = malloc(map->cols + 1);
	int i = 0;
	while (i < len) {
	    map->grid[0][i] = buf[i];
	    i++;
	}
	map->grid[0][i] = 0;

	int row = 1;
	while (row < map->rows) {
		len = read_line(fd, buf);
		if (len != map->cols) return 0;
		map->grid[row] = malloc(map->cols + 1);
		i = 0;
		while (i < len) {
			map->grid[row][i] = buf[i];
			i++;
		}
		map->grid[row][i] = 0;
		row++;
	}
	return 1;
}

void free_map(t_map *map)
{
	int i = 0;
	while (i < map->rows)
		free(map->grid[i++]);
	free(map->grid);
}
