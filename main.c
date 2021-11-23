#include "so_long.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef struct		s_param
{
	int				last_key;
	void			*img;
	void			*tile;
	void			*mlx;
	void			*win;
	t_user_sprites	user_sprites;
	t_exit_sprites	exit_sprites;
	t_coin_sprites	coin_sprites;
	int				x;
	int				y;
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
}

int					key_press(int keycode, t_param *param)
{
	static int	a;

	a = 0;
	if (keycode == KEY_D) // Action when W key pressed
		param->y++;
	else if (keycode == KEY_S) // Action when S key pressed
		param->y--;
	if (keycode == KEY_A) // Action when W key pressed
		param->x--;
	else if (keycode == KEY_D) // Action when S key pressed
		param->x++;
	else if (keycode == KEY_ESC) // Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
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

// int	direction_key_hook(int keycode, t_param *param)
// {
// 	if (keycode == KEY_W)
// 		param->direction = "UP";
// 	else if (keycode == KEY_S)
// 		param->direction = "DOWN";
// 	else if (keycode == KEY_A)
// 		param->direction = "LEFT";
// 	else if (keycode == KEY_D)
// 		param->direction = "RIGHT";
// 	return (0);
// }

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

int					main(void)
{
	void	*win;
	t_param	param;
	int		img_width;
	int		img_height;

	// void		*mlx;
	param_init(&param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx_project");
	mlx_key_hook(param.win, key_hook, &param);
	// sprite test
	load_images(&param);
	param.tile = mlx_xpm_file_to_image(
		param.mlx, "sprites/tile.xpm", &img_width, &img_height);
	mlx_loop_hook(param.mlx, *ft_update, &param);
	mlx_loop(param.mlx);
}
