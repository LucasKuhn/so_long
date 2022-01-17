/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:56:40 by lalexk-ku         #+#    #+#             */
/*   Updated: 2022/01/17 16:02:53 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 65307
# define BTN_X 17
# define NO_EVENT 0L
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 114
# define KEY_P 35
# define WHITE 0xF0F8FF

# include "libft/libft.h"
# include <fcntl.h> // Open
# include <unistd.h> // Read
# include <mlx.h> // MiniLibX
# include <stdio.h> // Printf
# include <stdlib.h> // Exit

typedef struct s_user_sprites
{
	void			*current;
	void			*w_0;
	void			*w_1;
	void			*w_2;
	void			*w_3;
	void			*a_0;
	void			*a_1;
	void			*a_2;
	void			*a_3;
	void			*s_0;
	void			*s_1;
	void			*s_2;
	void			*s_3;
	void			*d_0;
	void			*d_1;
	void			*d_2;
	void			*d_3;
}					t_user_sprites;

typedef struct s_exit_sprites
{
	void			*open;
	void			*closed;
}					t_exit_sprites;

typedef struct s_coin_sprites
{
	void			*coin_0;
	void			*coin_1;
	void			*coin_2;
	void			*coin_3;
}					t_coin_sprites;

typedef struct s_ghost_sprites
{
	void			*ghost_0;
	void			*ghost_1;
	void			*ghost_2;
	void			*ghost_3;
}					t_ghost_sprites;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*tile;
	void			*wall;
	char			*map_file;
	int				game_ended;
	int				last_key;
	int				moves;
	int				collected_coins;
	int				coins;
	t_user_sprites	user_sprites;
	t_exit_sprites	exit_sprites;
	t_coin_sprites	coin_sprites;
	t_ghost_sprites	ghost_sprites;
	int				x;
	int				y;
	char			**map;
	int				map_width;
	int				map_height;
	int				map_valid;
}					t_game;

void				draw_player(t_game *param, int frame, int x, int y);
void				print_tile(t_game *game, void *sprite, int x, int y);
void				draw_map(t_game *game, int frame);
int					close_game(t_game *game);
int					free_map(t_game *game);
int					validate_map(t_game *game);
void				load_map(t_game *game);
int					game_complete(t_game *game);
int					is_movement_key(int keycode);
int					handle_movement(int keycode, t_game *game);
void				load_map(t_game *game);
void				load_images(t_game *game);
void				load_user_sprites(t_game *game);
int					game_over(t_game *game);
void				draw_map(t_game *game, int frame);
void				draw_coin(t_game *game, int x, int y);
void				draw_ghost(t_game *game, int frame, int x, int y);
void				draw_exit(t_game *game, int x, int y);
void				draw_moves(t_game *game);
void				print_error(char *message, t_game *game);
size_t				ft_arrlen(char **arr);

#endif
