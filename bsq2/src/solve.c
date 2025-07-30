/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:46 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 15:13:39 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

static int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	find_square(t_map *map)
{
	int	**dp;
	int	max;
	int	mi;
	int	mj;
	int	i;
	int	j;

	dp = malloc(map->rows * sizeof(int *));
	max = 0;
	mi = 0;
	mj = 0;
	i = 0;
	while (i < map->rows)
	{
		dp[i] = malloc(map->cols * sizeof(int));
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obst)
				dp[i][j] = 0;
			else 
			{
				dp[i][j] = 1;
				if (i && j)
					dp[i][j] += min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
				if (dp[i][j] > max)
				{ 
					max = dp[i][j];
					mi = i;
					mj = j;
				}
			}
			j++;
		}
		i++;
	}
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
	i = 0;
	while (i < map->rows)
		free(dp[i++]);
	free(dp);
}
