/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maytgarc <maytgarc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:27:16 by maytgarc          #+#    #+#             */
/*   Updated: 2025/07/30 10:43:05 by maytgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_map	map;

	i = 1;
	while (i < argc || (argc == 1 && i == 1))
	{
		fd = 0;
		map = (t_map){0};
		if (argc > 1)
			fd = open(argv[i], O_RDONLY);
		if (fd == -1 || !parse_map(fd, &map))
			print_error();
		else
		{
			find_square(&map);
			print_map(&map);
			free_map(&map);
		}
		if (fd > 0)
			close(fd);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
