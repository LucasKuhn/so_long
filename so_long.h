#include "libft/libft.h"

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Open
#include <unistd.h> // Read

// QUIT
#define KEY_ESC 53

// X11 KEY EVENTS
#define BTN_X 17

// X11 MASKS
#define NO_EVENT 0L

// MOVEMENT
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

// RESTART
#define KEY_R 15
#define KEY_E 14

// PRINT
#define KEY_P 35

// TILE
#define TILE_SIZE 64

typedef struct		s_user_sprites
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

typedef struct		s_exit_sprites
{
	void			*open;
	void			*closed;
}					t_exit_sprites;

typedef struct		s_coin_sprites
{
	void			*coin_0;
	void			*coin_1;
	void			*coin_2;
	void			*coin_3;
}					t_coin_sprites;

typedef struct		s_ghost_sprites
{
	void			*ghost_0;
	void			*ghost_1;
	void			*ghost_2;
	void			*ghost_3;
}					t_ghost_sprites;

typedef struct		s_game
{
	int				game_ended;
	int				last_key;
	char			*map_file;
	void			*tile;
	void			*wall;
	void			*mlx;
	void			*win;
	void			*coin;
	int				coins;
	int				collected_coins;
	int				collected_all;
	t_user_sprites	user_sprites;
	t_exit_sprites	exit_sprites;
	t_coin_sprites	coin_sprites;
	t_ghost_sprites	ghost_sprites;
	int				x;
	int				y;
	char			**map;
	int				map_width;
	int				map_height;
}					t_game;

void	draw_player(t_game *param, int frame, int x, int y);
void	print_tile(t_game *game, void *sprite, int x, int y);
