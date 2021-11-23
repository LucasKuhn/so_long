#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.
typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
	void 	*img;
	void 	*tile;
	void 	*mlx;
	void 	*win;
	void 	*sprite0;
	void 	*sprite1;
	void 	*sprite2;
	void 	*sprite3;

}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 3;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

void load_images(t_param *param)
{
	// sprite test
	int		img_width;
	int 	img_height;
	param->sprite0 = mlx_xpm_file_to_image(param->mlx, "sprites/down_0.xpm", &img_width, &img_height);
	param->sprite1 = mlx_xpm_file_to_image(param->mlx, "sprites/down_1.xpm", &img_width, &img_height);
	param->sprite2 = mlx_xpm_file_to_image(param->mlx, "sprites/down_2.xpm", &img_width, &img_height);
	param->sprite3 = mlx_xpm_file_to_image(param->mlx, "sprites/down_3.xpm", &img_width, &img_height);
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_D)//Action when W key pressed
		param->y++;
	else if (keycode == KEY_S) //Action when S key pressed
		param->y--;
	if (keycode == KEY_A)//Action when W key pressed
		param->x--;
	else if (keycode == KEY_D) //Action when S key pressed
		param->x++;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int	key_hook(int keycode, t_param *param)
{
	mlx_put_image_to_window(param->mlx, param->win, param->tile, param->x * 64, param->y * 64);
	if (keycode == KEY_W)
		param->y--;
	else if (keycode == KEY_S)
		param->y++;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
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

int	ft_update (t_param *param)
{
	// mlx function that clears the window
	// mlx_clear_window(param->mlx, param->win);

	static int	frame;
	if (frame == 25 * 0)
		param->img = param->sprite0;
	if (frame == 25 * 1)
		param->img = param->sprite1;
	if (frame == 25 * 2)
		param->img = param->sprite2;
	if (frame == 25 * 3)
		param->img = param->sprite3;
	if (frame == 25 * 4)
		frame = 0;
	frame++;
	mlx_put_image_to_window(param->mlx, param->win, param->img, param->x * 64, param->y * 64);

	return (0);
}

int			main(void)
{
	// void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx_project");
	mlx_key_hook(param.win, key_hook, &param);


	// sprite test
	int		img_width;
	int 	img_height;

	load_images(&param);
	param.img = mlx_xpm_file_to_image(param.mlx, "sprites/down_0.xpm", &img_width, &img_height);
	param.tile = mlx_xpm_file_to_image(param.mlx, "sprites/tile.xpm", &img_width, &img_height);
	mlx_loop_hook(param.mlx, *ft_update, &param);

	// void *img;
	// img = mlx_xpm_file_to_image(mlx, "sprites/down_0.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(param.mlx, param.win, param.img, 0, 0);
	// mlx_loop_hook(mlx, *ft_update, &param);
	// End sprite test

	mlx_loop(param.mlx);
}
