/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:29:46 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 17:40:09 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

static int	**allocate_dp(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		dp[i] = malloc(cols * sizeof(int));
		i++;
	}
	return (dp);
}

static void	free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(dp[i++]);
	free(dp);
}

void	find_square(t_map *map)
{
	int		**dp;
	t_axis	info;

	dp = allocate_dp(map->rows, map->cols);
	find_largest_square(map, dp, &info);
	fill_largest_square(map, info.max, info.mi, info.mj);
	free_dp(dp, map->rows);
}
