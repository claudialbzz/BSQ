/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:09:33 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 17:39:47 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define O_RDONLY 0
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
}	t_map;

typedef struct s_axis
{
	int	max;
	int	mi;
	int	mj;
}	t_axis;

//ERR
void	print_error(void);

//MAPPING & PARSE
int		parse_map(int fd, t_map *map);
void	free_map(t_map *map);
int		parse_first_line(int fd, t_map *map);
int		read_line(int fd, char *buf);

//PRINT
void	print_map(t_map *map);

//SOLVE
void	find_square(t_map *map);
int		min(int a, int b, int c);
int		calculate_dp_value(int **dp, t_map *map, int i, int j);
void	update_max(t_axis *info, int value, int i, int j);
void	find_largest_square(t_map *map, int **dp, t_axis *info);
void	fill_largest_square(t_map *map, int max, int mi, int mj);

#endif
