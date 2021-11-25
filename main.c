#include "so_long.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Open
#include <unistd.h> // Read

typedef struct		s_user_sprites
{
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
	int				last_key;
	void			*img;
	void			*tile;
	void			*wall;
	void			*mlx;
	void			*win;
	t_user_sprites	user_sprites;
	t_exit_sprites	exit_sprites;
	t_coin_sprites	coin_sprites;
	t_ghost_sprites	ghost_sprites;
	int				x;
	int				y;
	char			**map;
}	t_param;



void				param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
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
	param->img = param->user_sprites.s_0;
}

int					key_hook(int keycode, t_param *param)
{
	mlx_put_image_to_window(
		param->mlx, param->win, param->tile, param->x * 64, param->y * 64);
	if (keycode == KEY_W)
	{
		param->y--;
		param->last_key = keycode;
	}
	else if (keycode == KEY_S)
	{
		param->y++;
		param->last_key = keycode;
	}
	else if (keycode == KEY_A)
	{
		param->x--;
		param->last_key = keycode;
	}
	else if (keycode == KEY_D)
	{
		param->x++;
		param->last_key = keycode;
	}
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	ft_update(t_param *param)
{
	static int	frame;
	static int	current_key;

	if ( param->last_key != current_key )
	{
		frame = 0;
		current_key = param->last_key;
	}
	if (param->last_key == KEY_W)
	{
		if (frame == 15 * 0)
			param->img = param->user_sprites.w_0;
		if (frame == 15 * 1)
			param->img = param->user_sprites.w_1;
		if (frame == 15 * 2)
			param->img = param->user_sprites.w_2;
		if (frame == 15 * 3)
			param->img = param->user_sprites.w_3;
	}
	if (param->last_key == KEY_A)
	{
		if (frame == 15 * 0)
			param->img = param->user_sprites.a_0;
		if (frame == 15 * 1)
			param->img = param->user_sprites.a_1;
		if (frame == 15 * 2)
			param->img = param->user_sprites.a_2;
		if (frame == 15 * 3)
			param->img = param->user_sprites.a_3;
	}
	if (param->last_key == KEY_S)
	{
		if (frame == 15 * 0)
			param->img = param->user_sprites.s_0;
		if (frame == 15 * 1)
			param->img = param->user_sprites.s_1;
		if (frame == 15 * 2)
			param->img = param->user_sprites.s_2;
		if (frame == 15 * 3)
			param->img = param->user_sprites.s_3;
	}
	if (param->last_key == KEY_D)
	{
		if (frame == 15 * 0)
			param->img = param->user_sprites.d_0;
		if (frame == 15 * 1)
			param->img = param->user_sprites.d_1;
		if (frame == 15 * 2)
			param->img = param->user_sprites.d_2;
		if (frame == 15 * 3)
			param->img = param->user_sprites.d_3;
	}
	if (frame == 15 * 4)
		frame = 0;
	else
		frame++;

	mlx_put_image_to_window(
		param->mlx, param->win, param->img, param->x * 64, param->y * 64);
	return (0);
}

void load_map(t_param	*param, char *file_path)
{
	int fd = open(file_path, O_RDONLY);
	char		read_buffer[1024];
	read(fd, read_buffer, 1024);
	// // If the above is lower than 0, throw an error
	param->map = ft_split(read_buffer, '\n');
	int i;
	int j;
	i = 0;
	printf("%s\n", param->map[0]);
	printf("%s\n", param->map[1]);
	printf("%s\n", param->map[2]);
	printf("%s\n", param->map[3]);
	printf("%s\n", param->map[4]);
	printf("--\n\n");
	while (param->map[i])
	{
		j = 0;
		while(param->map[i][j])
		{
			printf("[%d][%d] -> %c\n", i, j, param->map[i][j]);
			if (param->map[i][j] == '1')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->wall, j*64, i*64);
			}
			if (param->map[i][j] == '0')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->tile, j*64, i*64);
			}
			if (param->map[i][j] == 'E')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->exit_sprites.closed, j*64, i*64);
			}
			if (param->map[i][j] == 'C')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->coin_sprites.coin_0, j*64, i*64);
			}
			if (param->map[i][j] == 'P')
			{
				param->x = j;
				param->y = i;
			}
			if (param->map[i][j] == 'G')
			{
				mlx_put_image_to_window(
					param->mlx, param->win, param->ghost_sprites.ghost_0, j*64, i*64);
			}
			j++;
		}
		i++;
	}

}

int	main(int argc, char **argv)
{
	void	*win;
	t_param	param;
	int		img_width;
	int		img_height;

	// void		*mlx;
	param_init(&param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 800, 800, "mlx_project");
	mlx_key_hook(param.win, key_hook, &param);
	// sprite test
	load_images(&param);
	load_user_sprites(&param);
	load_map(&param, argv[1]);
	mlx_loop_hook(param.mlx, *ft_update, &param);
	mlx_loop(param.mlx);
}
