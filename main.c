#include "so_long.h"

int game_over(t_game *game)
{
	int x;
	int y;

	void *sprite;
	int sprite_w;
	int sprite_h;


	sprite = mlx_xpm_file_to_image(game->mlx, "sprites/game_over.xpm", &sprite_w, &sprite_h);
	printf("game->map_width:%d game->map_height:%d\n\n", game->map_width, game->map_height);
	x = (game->map_width  / 2) - (sprite_w/2);
	y = (game->map_height / 2) - (sprite_h/2);
	printf("X:%d Y:%d\n\n", x, y);
	mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
	mlx_destroy_image (game->mlx, sprite);

	game->game_ended = 1;
	return(0);
}

int game_complete(t_game *param)
{
	param->game_ended = 1;
	return(0);
}

int close_game()
{
	exit(0);
}


void				param_init(t_game *param)
{
	param->game_ended = 0;
	param->collected_coins = 0;
	param->last_key = KEY_S;
}

void				load_images(t_game *param)
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

void				load_user_sprites(t_game *param)
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

char get_next_tile(int keycode, t_game *param)
{
	int next_x;
	int next_y;

	next_x = param->x;
	next_y = param->y;
	if (keycode == KEY_W)
		next_y--;
	if (keycode == KEY_S)
		next_y++;
	if (keycode == KEY_A)
		next_x--;
	if (keycode == KEY_D)
		next_x++;
	return ( param->map[next_y][next_x] );
}

int handle_movement(int keycode, t_game *param)
{
	char next_tile;

	next_tile = get_next_tile(keycode, param);
	if (next_tile == '1')
		return(0);
	if (next_tile == 'C')
		param->collected_coins++;
	if (next_tile == 'G')
		return(game_over(param));
	// if (next_tile == 'E')
	// 	game_complete(param);

	param->last_key = keycode;
	param->map[param->y][param->x] = '0';
	if (keycode == KEY_W)
		param->y--;
	if (keycode == KEY_S)
		param->y++;
	if (keycode == KEY_A)
		param->x--;
	if (keycode == KEY_D)
		param->x++;
	param->map[param->y][param->x] = 'P';
	return (0);
}

void draw_coin(t_game *param, int x, int y)
{
	if (x % 2 == 0 && y % 2 == 0)
		print_tile(param, param->coin_sprites.coin_0, x, y);
	if (x % 2 == 0 && y % 2 != 0)
		print_tile(param, param->coin_sprites.coin_1, x, y);
	if (x % 2 != 0 && y % 2 == 0)
		print_tile(param, param->coin_sprites.coin_2, x, y);
	if (x % 2 != 0 && y % 2 != 0)
		print_tile(param, param->coin_sprites.coin_3, x, y);
	return ;
}

void draw_ghost(t_game *param, int frame, int x, int y)
{
	if (frame == 30 * 0)
		print_tile(param, param->ghost_sprites.ghost_0, x, y);
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


void draw_map(t_game	*param, int frame)
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

int	ft_update(t_game *param)
{
	static int	frame;

	if (param->game_ended)
		return(0);
	draw_map(param, frame);
	if (frame == 15 * 8)
		frame = 0;
	else
		frame++;
	return (0);
}

void load_map(t_game	*param, char *file_path)
{
	int fd = open(file_path, O_RDONLY);
	char		read_buffer[1024];
	int read_int = read(fd, read_buffer, 1024);
	printf("read int: %d", read_int);
	close(fd);
	// // If the above is lower than 0, throw an error
	free(param->map);
	param->map = NULL;
	param->map = ft_split(read_buffer, '\n');

	printf("~~ map loaded : ~~\n");
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

void print_map(t_game *param)
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

int	free_map(t_game *param)
{
	int y;

	y = 0;
	while (param->map[y])
	{
		free(param->map[y]);
		param->map[y] = NULL;
	}
	free(param->map);
	param->map = NULL;
	return(0);
}

int	key_hook(int keycode, t_game *param)
{
	if (keycode == KEY_ESC)
		return(close_game());
	if (keycode == KEY_R)
	{
		param_init(param);
		free_map(param);
		load_map(param, param->map_file);
	}
	if (keycode == KEY_P)
	{
		print_map(param);
		// game_over(param);
	}
	if (param->game_ended)
		return (0);
	handle_movement(keycode, param);
	return(0);
}

int	main(int argc, char **argv)
{
	void	*win;
	t_game	param;
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
