/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:51:57 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 17:40:45 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int	calculate_dp_value(int **dp, t_map *map, int i, int j)
{
	if (map->grid[i][j] == map->obst)
		return (0);
	if (i == 0 || j == 0)
		return (1);
	return (1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]));
}

void	update_max(t_axis *info, int value, int i, int j)
{
	if (value > info->max)
	{
		info->max = value;
		info->mi = i;
		info->mj = j;
	}
}

void	find_largest_square(t_map *map, int **dp, t_axis *info)
{
	int	i;
	int	j;
	int	value;

	info->max = 0;
	info->mi = 0;
	info->mj = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			value = calculate_dp_value(dp, map, i, j);
			dp[i][j] = value;
			update_max(info, value, i, j);
			j++;
		}
		i++;
	}
}

void	fill_largest_square(t_map *map, int max, int mi, int mj)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			map->grid[mi - i][mj - j] = map->full;
			j++;
		}
		i++;
	}
}
