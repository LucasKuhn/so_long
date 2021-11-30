/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:29:05 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/11/29 22:12:45 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game, int frame)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				print_tile(game, game->wall, x, y);
			if (game->map[y][x] == '0')
				print_tile(game, game->tile, x, y);
			if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
			if (game->map[y][x] == 'C')
				draw_coin(game, x, y);
			if (game->map[y][x] == 'P')
				draw_player(game, frame, x, y);
			if (game->map[y][x] == 'G')
				draw_ghost(game, frame, x, y);
			x++;
		}
		y++;
	}
}

void	draw_coin(t_game *game, int x, int y)
{
	if (x % 2 == 0 && y % 2 == 0)
		print_tile(game, game->coin_sprites.coin_0, x, y);
	if (x % 2 == 0 && y % 2 != 0)
		print_tile(game, game->coin_sprites.coin_1, x, y);
	if (x % 2 != 0 && y % 2 == 0)
		print_tile(game, game->coin_sprites.coin_2, x, y);
	if (x % 2 != 0 && y % 2 != 0)
		print_tile(game, game->coin_sprites.coin_3, x, y);
	return ;
}

void	draw_ghost(t_game *game, int frame, int x, int y)
{
	if (frame == 30 * 0)
		print_tile(game, game->ghost_sprites.ghost_0, x, y);
	if (frame == 30 * 1)
		print_tile(game, game->ghost_sprites.ghost_1, x, y);
	if (frame == 30 * 2)
		print_tile(game, game->ghost_sprites.ghost_2, x, y);
	if (frame == 30 * 3)
		print_tile(game, game->ghost_sprites.ghost_3, x, y);
}

void	draw_exit(t_game *game, int x, int y)
{
	if (game->collected_coins == game->coins)
		print_tile(game, game->exit_sprites.open, x, y);
	else
		print_tile(game, game->exit_sprites.closed, x, y);
}

void	draw_moves(t_game *game)
{
	int	x;
	int	y;

	x = (game->map_width / 2) - 5;
	y = (game->map_height / 2);
	mlx_string_put(game->mlx, game->win, x, y, WHITE, ft_itoa(game->moves));
}
