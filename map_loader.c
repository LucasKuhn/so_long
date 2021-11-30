/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:02:09 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/11/29 22:05:28 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		printf("%s\n", game->map[y]);
		y++;
	}
}

void	init_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
			}
			if (game->map[y][x] == 'C')
				game->coins++;
			x++;
		}
		y++;
	}
	game->map_width = x * 64;
	game->map_height = y * 64;
}

void	load_map(t_game *game)
{
	int		fd;
	char	read_buffer[1024];
	int		read_int;

	fd = open(game->map_file, O_RDONLY);
	ft_bzero(read_buffer, 1024);
	read_int = read(fd, read_buffer, 1024);
	close(fd);
	game->map = ft_split(read_buffer, '\n');
	init_map(game);
}

int	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		game->map[y] = NULL;
		y++;
	}
	free(game->map);
	game->map = NULL;
	return (0);
}
