/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:30:58 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/11/29 21:30:59 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int				w;
	int				h;
	void			*mlx;
	t_exit_sprites	*exit;
	t_coin_sprites	*coins;
	t_ghost_sprites	*ghosts;

	mlx = game->mlx;
	exit = &game->exit_sprites;
	coins = &game->coin_sprites;
	ghosts = &game->ghost_sprites;
	game->wall = mlx_xpm_file_to_image(mlx, "sprites/tree.xpm", &w, &h);
	game->tile = mlx_xpm_file_to_image(mlx, "sprites/tile.xpm", &w, &h);
	exit->open = mlx_xpm_file_to_image(mlx, "sprites/e_open.xpm", &w, &h);
	exit->closed = mlx_xpm_file_to_image(mlx, "sprites/e_closed.xpm", &w, &h);
	coins->coin_0 = mlx_xpm_file_to_image(mlx, "sprites/c_0.xpm", &w, &h);
	coins->coin_1 = mlx_xpm_file_to_image(mlx, "sprites/c_1.xpm", &w, &h);
	coins->coin_2 = mlx_xpm_file_to_image(mlx, "sprites/c_2.xpm", &w, &h);
	coins->coin_3 = mlx_xpm_file_to_image(mlx, "sprites/c_3.xpm", &w, &h);
	ghosts->ghost_0 = mlx_xpm_file_to_image(mlx, "sprites/g_0.xpm", &w, &h);
	ghosts->ghost_1 = mlx_xpm_file_to_image(mlx, "sprites/g_1.xpm", &w, &h);
	ghosts->ghost_2 = mlx_xpm_file_to_image(mlx, "sprites/g_2.xpm", &w, &h);
	ghosts->ghost_3 = mlx_xpm_file_to_image(mlx, "sprites/g_3.xpm", &w, &h);
}

void	load_user_sprites(t_game *game)
{
	int				w;
	int				h;
	t_user_sprites	*user;

	user = &game->user_sprites;
	user->s_0 = mlx_xpm_file_to_image(game->mlx, "sprites/s_0.xpm", &w, &h);
	user->s_1 = mlx_xpm_file_to_image(game->mlx, "sprites/s_1.xpm", &w, &h);
	user->s_2 = mlx_xpm_file_to_image(game->mlx, "sprites/s_2.xpm", &w, &h);
	user->s_3 = mlx_xpm_file_to_image(game->mlx, "sprites/s_3.xpm", &w, &h);
	user->w_0 = mlx_xpm_file_to_image(game->mlx, "sprites/w_0.xpm", &w, &h);
	user->w_1 = mlx_xpm_file_to_image(game->mlx, "sprites/w_1.xpm", &w, &h);
	user->w_2 = mlx_xpm_file_to_image(game->mlx, "sprites/w_2.xpm", &w, &h);
	user->w_3 = mlx_xpm_file_to_image(game->mlx, "sprites/w_3.xpm", &w, &h);
	user->a_0 = mlx_xpm_file_to_image(game->mlx, "sprites/a_0.xpm", &w, &h);
	user->a_1 = mlx_xpm_file_to_image(game->mlx, "sprites/a_1.xpm", &w, &h);
	user->a_2 = mlx_xpm_file_to_image(game->mlx, "sprites/a_2.xpm", &w, &h);
	user->a_3 = mlx_xpm_file_to_image(game->mlx, "sprites/a_3.xpm", &w, &h);
	user->d_0 = mlx_xpm_file_to_image(game->mlx, "sprites/d_0.xpm", &w, &h);
	user->d_1 = mlx_xpm_file_to_image(game->mlx, "sprites/d_1.xpm", &w, &h);
	user->d_2 = mlx_xpm_file_to_image(game->mlx, "sprites/d_2.xpm", &w, &h);
	user->d_3 = mlx_xpm_file_to_image(game->mlx, "sprites/d_3.xpm", &w, &h);
	user->current = user->s_0;
}
