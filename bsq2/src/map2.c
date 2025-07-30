/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudialbombin <claudialbombin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:23:23 by claudialbom       #+#    #+#             */
/*   Updated: 2025/07/30 16:23:24 by claudialbom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

static int	init_grid(t_map *map, int len, char *buf)
{
	int	i;

	map->cols = len;
	map->grid = malloc(map->rows * sizeof(char *));
	if (!map->grid)
		return (0);
	map->grid[0] = malloc(len + 1);
	if (!map->grid[0])
		return (0);
	i = 0;
	while (i < len)
		map->grid[0][i] = buf[i++];
	map->grid[0][i] = 0;
	return (1);
}

static int	fill_row(t_map *map, int row, int len, char *buf)
{
	int	i;

	map->grid[row] = malloc(len + 1);
	if (!map->grid[row])
		return (0);
	i = 0;
	while (i < len)
		map->grid[row][i] = buf[i++];
	map->grid[row][i] = 0;
	return (1);
}

int	parse_map(int fd, t_map *map)
{
	char	buf[1024];
	int		len;
	int		i;
	int		row;

	if (!parse_first_line(fd, map))
		return (0);
	len = read_line(fd, buf);
	if (len <= 0 || !init_grid(map, len, buf))
		return (0);
	row = 1;
	while (row++ < map->rows)
	{
		len = read_line(fd, buf);
		if (len != map->cols || !fill_row(map, row, len, buf))
			return (0);
	}
	return (1);
}
