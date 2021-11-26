#include "so_long.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Open
#include <unistd.h> // Read

typedef struct		s_user_sprites
{
	void	*current;
	void	*w_0;
	void	*w_1;
	void	*w_2;
	void	*w_3;
	void	*a_0;
	void	*a_1;
	void	*a_2;
	void	*a_3;
	void	*s_0;
	void	*s_1;
	void	*s_2;
	void	*s_3;
	void	*d_0;
	void	*d_1;
	void	*d_2;
	void	*d_3;
}					t_user_sprites;

typedef struct		s_exit_sprites
{
	void	*open;
	void	*closed;
}	t_exit_sprites;

typedef struct		s_coin_sprites
{
	void	*coin_0;
	void	*coin_1;
	void	*coin_2;
	void	*coin_3;
}	t_coin_sprites;

typedef struct		s_ghost_sprites
{
	void	*ghost_0;
	void	*ghost_1;
	void	*ghost_2;
	void	*ghost_3;
}	t_ghost_sprites;

typedef struct		s_param
{
	char			*map_file;
	int				game_ended;
	int				last_key;
	void			*tile;
	void			*wall;
	void			*mlx;
	void			*win;
	void			*coin;
	t_user_sprites	user_sprites;
	t_exit_sprites	exit_sprites;
	t_coin_sprites	coin_sprites;
	t_ghost_sprites	ghost_sprites;
	int				x;
	int				y;
	char			**map;
	int map_width;
	int map_height;
}	t_param;



void				param_init(t_param *param)
{
	// param->x = 0;
	// param->y = 0;
	param->game_ended = 0;
	param->last_key = KEY_S;
}

void				load_images(t_param *param)
{
	int	w;
	int	h;
	void * mlx;
	t_exit_sprites *exit;
	t_coin_sprites *coins;
	t_ghost_sprites *ghosts;

	mlx = &param->mlx;
	exit = &param->exit_sprites;
	coins = &param->coin_sprites;
	ghosts = &param->ghost_sprites;
	param->wall = mlx_xpm_file_to_image(mlx, "sprites/tree.xpm", &w, &h);
	param->tile = mlx_xpm_file_to_image(mlx, "sprites/tile.xpm", &w, &h);
	exit->open = mlx_xpm_file_to_image(mlx, "sprites/e_open.xpm", &w, &h);
	exit->closed = mlx_xpm_file_to_image(mlx, "sprites/e_closed.xpm", &w, &h);
	coins->coin_0 = mlx_xpm_file_to_image(param->mlx, "sprites/c_0.xpm", &w, &h);
	coins->coin_1 = mlx_xpm_file_to_image(param->mlx, "sprites/c_1.xpm", &w, &h);
	coins->coin_2 = mlx_xpm_file_to_image(param->mlx, "sprites/c_2.xpm", &w, &h);
	coins->coin_3 = mlx_xpm_file_to_image(param->mlx, "sprites/c_3.xpm", &w, &h);
	ghosts->ghost_0 = mlx_xpm_file_to_image(param->mlx, "sprites/g_0.xpm", &w, &h);
	ghosts->ghost_1 = mlx_xpm_file_to_image(param->mlx, "sprites/g_1.xpm", &w, &h);
	ghosts->ghost_2 = mlx_xpm_file_to_image(param->mlx, "sprites/g_2.xpm", &w, &h);
	ghosts->ghost_3 = mlx_xpm_file_to_image(param->mlx, "sprites/g_3.xpm", &w, &h);
	param->coin = coins->coin_0;
}

void				load_user_sprites(t_param *param)
{
	int	w;
	int	h;
	t_user_sprites *user;

	user = &param->user_sprites;
	user->s_0 = mlx_xpm_file_to_image(param->mlx, "sprites/s_0.xpm", &w, &h);
	user->s_1 = mlx_xpm_file_to_image(param->mlx, "sprites/s_1.xpm", &w, &h);
	user->s_2 = mlx_xpm_file_to_image(param->mlx, "sprites/s_2.xpm", &w, &h);
	user->s_3 = mlx_xpm_file_to_image(param->mlx, "sprites/s_3.xpm", &w, &h);
	user->w_0 = mlx_xpm_file_to_image(param->mlx, "sprites/w_0.xpm", &w, &h);
	user->w_1 = mlx_xpm_file_to_image(param->mlx, "sprites/w_1.xpm", &w, &h);
	user->w_2 = mlx_xpm_file_to_image(param->mlx, "sprites/w_2.xpm", &w, &h);
	user->w_3 = mlx_xpm_file_to_image(param->mlx, "sprites/w_3.xpm", &w, &h);
	user->a_0 = mlx_xpm_file_to_image(param->mlx, "sprites/a_0.xpm", &w, &h);
	user->a_1 = mlx_xpm_file_to_image(param->mlx, "sprites/a_1.xpm", &w, &h);
	user->a_2 = mlx_xpm_file_to_image(param->mlx, "sprites/a_2.xpm", &w, &h);
	user->a_3 = mlx_xpm_file_to_image(param->mlx, "sprites/a_3.xpm", &w, &h);
	user->d_0 = mlx_xpm_file_to_image(param->mlx, "sprites/d_0.xpm", &w, &h);
	user->d_1 = mlx_xpm_file_to_image(param->mlx, "sprites/d_1.xpm", &w, &h);
	user->d_2 = mlx_xpm_file_to_image(param->mlx, "sprites/d_2.xpm", &w, &h);
	user->d_3 = mlx_xpm_file_to_image(param->mlx, "sprites/d_3.xpm", &w, &h);
	user->current = user->s_0;
}

int handle_movement(int keycode, t_param *param)
{

	param->last_key = keycode;
	param->map[param->y][param->x] = '0';

	if (keycode == KEY_W)
	{
		param->y--;
	}
	if (keycode == KEY_S)
	{
		param->y++;
	}
	if (keycode == KEY_A)
	{
		param->x--;
	}
	if (keycode == KEY_D)
	{
		param->x++;
	}
	param->map[param->y][param->x] = 'P';
	return (0);
}

int close_game()
{
	exit(0);
}

void draw_player(t_param *param, int frame, int x, int y)
{
	static int		current_key;
	t_user_sprites	*user_sprites;

	if (frame >= 60)
		frame = frame - 60;
	if ( param->last_key != current_key )
	{
		frame = 0;
		current_key = param->last_key;
	}
	sprites = &param->user_sprites;
	if (param->last_key == KEY_W)
	{
		if (frame == 15 * 0)
			sprites->current = sprites.w_0;
		if (frame == 15 * 1)
			sprites->current = sprites.w_1;
		if (frame == 15 * 2)
			sprites->current = sprites.w_2;
		if (frame == 15 * 3)
			sprites->current = sprites.w_3;
	}
	if (param->last_key == KEY_A)
	{
		if (frame == 15 * 0)
			sprites->current = sprites.a_0;
		if (frame == 15 * 1)
			sprites->current = sprites.a_1;
		if (frame == 15 * 2)
			sprites->current = sprites.a_2;
		if (frame == 15 * 3)
			sprites->current = sprites.a_3;
	}
	if (param->last_key == KEY_S)
	{
		if (frame == 15 * 0)
			sprites->current = sprites.s_0;
		if (frame == 15 * 1)
			sprites->current = sprites.s_1;
		if (frame == 15 * 2)
			sprites->current = sprites.s_2;
		if (frame == 15 * 3)
			sprites->current = sprites.s_3;
	}
	if (param->last_key == KEY_D)
	{
		if (frame == 15 * 0)
			sprites->current = sprites.d_0;
		if (frame == 15 * 1)
			sprites->current = sprites.d_1;
		if (frame == 15 * 2)
			sprites->current = sprites.d_2;
		if (frame == 15 * 3)
			sprites->current = sprites.d_3;
	}
	mlx_put_image_to_window(
		param->mlx, param->win, sprites->current, x * 64, y * 64);
}

void draw_coin(t_param *param, int x, int y)
{
	if (x % 2 == 0 && y % 2 == 0)
		mlx_put_image_to_window(
			param->mlx, param->win, param->coin_sprites.coin_0, x*64, y*64);
	if (x % 2 == 0 && y % 2 != 0)
		mlx_put_image_to_window(
			param->mlx, param->win, param->coin_sprites.coin_1, x*64, y*64);
	if (x % 2 != 0 && y % 2 == 0)
		mlx_put_image_to_window(
			param->mlx, param->win, param->coin_sprites.coin_2, x*64, y*64);
	if (x % 2 != 0 && y % 2 != 0)
		mlx_put_image_to_window(
			param->mlx, param->win, param->coin_sprites.coin_3, x*64, y*64);
	return ;
}

void draw_ghost(t_param *param, int frame, int x, int y)
{
	if (frame == 30 * 0)
		mlx_put_image_to_window(
			param->mlx, param->win, param->ghost_sprites.ghost_0, x*64, y*64);
	if (frame == 30 * 1)
		mlx_put_image_to_window(
			param->mlx, param->win, param->ghost_sprites.ghost_1, x*64, y*64);
	if (frame == 30 * 2)
		mlx_put_image_to_window(
			param->mlx, param->win, param->ghost_sprites.ghost_2, x*64, y*64);
	if (frame == 30 * 3)
		mlx_put_image_to_window(
			param->mlx, param->win, param->ghost_sprites.ghost_3, x*64, y*64);
}


void draw_map(t_param	*param, int frame)
{
	int x;
	int y;

	y = 0;
	while (param->map[y])
	{
		x = 0;
		while(param->map[y][x])
		{
			if (param->map[y][x] == '1')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->wall, x*64, y*64);
			}
			if (param->map[y][x] == '0')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->tile, x*64, y*64);
			}
			if (param->map[y][x] == 'E')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->exit_sprites.closed, x*64, y*64);
			}
			if (param->map[y][x] == 'C')
			{
				draw_coin(param, x, y);
			}
			if (param->map[y][x] == 'P')
			{
				draw_player(param, frame, x, y);
			}
			if (param->map[y][x] == 'G')
			{
				draw_ghost(param, frame, x, y);
			}
			x++;
		}
		y++;
	}
}

int	ft_update(t_param *param)
{
	static int	frame;

	draw_map(param, frame);
	if (frame == 15 * 8)
		frame = 0;
	else
		frame++;
	return (0);
}

void load_map(t_param	*param, char *file_path)
{
	int fd = open(file_path, O_RDONLY);
	char		read_buffer[1024];
	read(fd, read_buffer, 1024);
	close(fd);
	// // If the above is lower than 0, throw an error
	param->map = ft_split(read_buffer, '\n');

	int x;
	int y;
	y = 0;
	while (param->map[y])
	{
		printf("%s\n", param->map[y]);
		x = 0;
		while(param->map[y][x])
		{
			if (param->map[y][x] == 'P')
			{
				param->x = x;
				param->y = y;
			}
			x++;
		}
		y++;
	}
	param->map_width	= x * 64;
	param->map_height	= y * 64;
	printf("--\n\n");

}

void print_map(t_param *param)
{
	int x;
	int y;

	y = 0;
	while (param->map[y])
	{
		printf("%s\n", param->map[y]);
		y++;
	}
	printf("\n");
	printf("Current P -> [%d][%d]", param->y, param->x);
	printf("\n\n");
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		return(close_game());
	if (keycode == KEY_R)
		load_map(param, param->map_file);
	if (keycode == KEY_P)
		print_map(param);
	if (param->game_ended)
		return (0);
	handle_movement(keycode, param);
	return(0);
}

int	main(int argc, char **argv)
{
	void	*win;
	t_param	param;
	int		img_width;
	int		img_height;


	param.map_file = argv[1];
	load_map(&param, param.map_file);
	param_init(&param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, param.map_width, param.map_height, "mlx_project");
	mlx_key_hook(param.win, key_hook, &param);
	load_images(&param);
	load_user_sprites(&param);

	mlx_hook(param.win, BTN_X, NO_EVENT, close_game, &param);
	mlx_loop_hook(param.mlx, *ft_update, &param);
	mlx_loop(param.mlx);
}
