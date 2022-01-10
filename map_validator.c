/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:02:09 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/06 19:41:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(t_game *game)
{
	char	*extension;

	extension = ft_strrchr(game->map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
	{
		print_error("Map is not a .ber file", game);
		game->map_valid = 0;
	}
}

void	check_walls(t_game *game)
{
	int		x;
	int		y;
	size_t	width;
	size_t	height;

	width = ft_strlen(game->map[y]);
	height = ft_arrlen(game->map);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		if (ft_strlen(game->map[y]) != width)
			print_error("Map is not rectangular", game);
		while (game->map[y][x])
		{
			if (y == 0 || x == 0 || x == width - 1 || y == height - 1)
			{
				if (game->map[y][x] != '1')
					print_error("Map not surrounded by walls", game);
			}
			x++;
		}
		y++;
	}
}

int	invalid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'G')
		return (0);
	return (1);
}

void	check_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (invalid_character(game->map[y][x]))
				print_error("Map contains an invalid character", game);
			x++;
		}
		y++;
	}
}

int	validate_map(t_game *game)
{
	game->map_valid = 1;
	check_extension(game);
	if (!game->map_valid)
		return (1);
	load_map(game);
	check_walls(game);
	check_characters(game);
	return (0);
}
