/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:03:42 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/11/29 22:09:43 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keycode, t_game *game);
int		is_movement_key(int keycode);
char	get_next_tile(int keycode, t_game *game);

int	handle_movement(int keycode, t_game *game)
{
	char	next_tile;

	game->last_key = keycode;
	next_tile = get_next_tile(keycode, game);
	if (next_tile == '1')
		return (0);
	if (next_tile == 'C')
		game->collected_coins++;
	if (next_tile == 'G')
		return (game_over(game));
	if (next_tile == 'E' && game->collected_coins == game->coins)
		return (game_complete(game));
	else if (next_tile == 'E')
		return (0);
	move_player(keycode, game);
	return (0);
}

char	get_next_tile(int keycode, t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->x;
	next_y = game->y;
	if (keycode == KEY_W)
		next_y--;
	if (keycode == KEY_S)
		next_y++;
	if (keycode == KEY_A)
		next_x--;
	if (keycode == KEY_D)
		next_x++;
	return (game->map[next_y][next_x]);
}

void	move_player(int keycode, t_game *game)
{
	game->moves++;
	game->map[game->y][game->x] = '0';
	if (keycode == KEY_W)
		game->y--;
	if (keycode == KEY_S)
		game->y++;
	if (keycode == KEY_A)
		game->x--;
	if (keycode == KEY_D)
		game->x++;
	game->map[game->y][game->x] = 'P';
}

int	is_movement_key(int keycode)
{
	return ((
			keycode == KEY_W
			|| keycode == KEY_A
			|| keycode == KEY_S
			|| keycode == KEY_D
		));
}
