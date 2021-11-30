/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:04:45 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/11/29 22:08:19 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// This is just an alias to avoid writing mlx_put_image_to_window
void	print_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * 64, y * 64);
}

int	close_game(t_game *game)
{
	exit(0);
}

int	game_over(t_game *game)
{
	int		x;
	int		y;
	void	*sprite;
	int		sprite_w;
	int		sprite_h;

	sprite = mlx_xpm_file_to_image(
			game->mlx, "sprites/game_over.xpm", &sprite_w, &sprite_h);
	x = (game->map_width / 2) - (sprite_w / 2);
	y = (game->map_height / 2) - (sprite_h / 2);
	mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
	mlx_destroy_image(game->mlx, sprite);
	sprite = NULL;
	game->game_ended = 1;
	return (0);
}

int	game_complete(t_game *game)
{
	int		x;
	int		y;
	void	*sprite;
	int		sprite_w;
	int		sprite_h;

	sprite = mlx_xpm_file_to_image(
			game->mlx, "sprites/you_win.xpm", &sprite_w, &sprite_h);
	x = (game->map_width / 2) - (sprite_w / 2);
	y = (game->map_height / 2) - (sprite_h / 2);
	mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
	mlx_destroy_image(game->mlx, sprite);
	sprite = NULL;
	game->game_ended = 1;
	return (0);
}
