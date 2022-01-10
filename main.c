/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:03:52 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/12/02 13:20:43 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->moves = 0;
	game->game_ended = 0;
	game->coins = 0;
	game->x = 0;
	game->y = 0;
	game->collected_coins = 0;
	game->last_key = KEY_S;
}

int	ft_update(t_game *game)
{
	static int	frame;

	if (game->game_ended)
		return (0);
	draw_map(game, frame);
	draw_moves(game);
	if (frame == 15 * 8)
		frame = 0;
	else
		frame++;
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	printf("Pressed key: %i", keycode);
	if (keycode == KEY_ESC)
		return (close_game(game));
	if (keycode == KEY_R)
	{
		game_init(game);
		free_map(game);
		load_map(game);
	}
	if (keycode == KEY_P)
		game_complete(game);
	if (game->game_ended)
		return (0);
	if (is_movement_key(keycode))
		handle_movement(keycode, game);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*win;
	t_game	game;

	game.map_file = argv[1];
	game_init(&game);
	validate_map(&game);
	if (!game.map_valid)
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(
			game.mlx, game.map_width, game.map_height, "so_long");
	mlx_key_hook(game.win, key_hook, &game);
	load_images(&game);
	load_user_sprites(&game);
	mlx_hook(game.win, BTN_X, NO_EVENT, close_game, &game);
	mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx);
}
