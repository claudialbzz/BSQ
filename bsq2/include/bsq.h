/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:09:33 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 10:21:21 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define O_RDONLY 0
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct {
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
}	t_map;

//ERR
void	print_error(void);

//MAPPING
int		parse_map(int fd, t_map *map);
void	free_map(t_map *map);

//PRINT
void	print_map(t_map *map);

//SOLVE
void	find_square(t_map *map);

#endif
