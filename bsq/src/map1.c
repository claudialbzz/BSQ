/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:43:30 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 16:56:35 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	read_line(int fd, char *buf)
{
	int	i;

	i = 0;
	while (read(fd, buf + i, 1) && buf[i] != '\n')
		i++;
	buf[i] = 0;
	return (i);
}

int	parse_first_line(int fd, t_map *map)
{
	char	buf[32];
	int		len;
	int		i;

	i = 0;
	len = read_line(fd, buf);
	if (len < 4)
		return (0);
	while (buf[i] >= '0' && buf[i] <= '9')
	{
		map->rows = map->rows * 10 + (buf[i] - '0');
		i++;
	}
	map->empty = buf[len - 3];
	map->obst = buf[len - 2];
	map->full = buf[len - 1];
	return (map->rows > 0 && map->empty != map->obst
		&& map->obst != map->full && map->empty != map->full);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
		free(map->grid[i++]);
	free(map->grid);
}
