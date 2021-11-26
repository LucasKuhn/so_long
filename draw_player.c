#include "so_long.h"

void	sprite_for_w(t_game *param, int frame, t_user_sprites *sprites)
{
	if (frame == 15 * 0)
		sprites->current = param->user_sprites.w_0;
	if (frame == 15 * 1)
		sprites->current = param->user_sprites.w_1;
	if (frame == 15 * 2)
		sprites->current = param->user_sprites.w_2;
	if (frame == 15 * 3)
		sprites->current = param->user_sprites.w_3;
}

void	sprite_for_a(t_game *param, int frame, t_user_sprites *sprites)
{
	if (frame == 15 * 0)
		sprites->current = param->user_sprites.a_0;
	if (frame == 15 * 1)
		sprites->current = param->user_sprites.a_1;
	if (frame == 15 * 2)
		sprites->current = param->user_sprites.a_2;
	if (frame == 15 * 3)
		sprites->current = param->user_sprites.a_3;
}

void	sprite_for_s(t_game *param, int frame, t_user_sprites *sprites)
{
	if (frame == 15 * 0)
		sprites->current = param->user_sprites.s_0;
	if (frame == 15 * 1)
		sprites->current = param->user_sprites.s_1;
	if (frame == 15 * 2)
		sprites->current = param->user_sprites.s_2;
	if (frame == 15 * 3)
		sprites->current = param->user_sprites.s_3;
}

void	sprite_for_d(t_game *param, int frame, t_user_sprites *sprites)
{
	if (frame == 15 * 0)
		sprites->current = param->user_sprites.d_0;
	if (frame == 15 * 1)
		sprites->current = param->user_sprites.d_1;
	if (frame == 15 * 2)
		sprites->current = param->user_sprites.d_2;
	if (frame == 15 * 3)
		sprites->current = param->user_sprites.d_3;
}

void	draw_player(t_game *param, int frame, int x, int y)
{
	static int		direction;
	t_user_sprites	*sprites;

	if (frame >= 60)
		frame = frame - 60;
	if (direction != param->last_key)
	{
		frame = 0;
		direction = param->last_key;
	}
	sprites = &param->user_sprites;
	if (direction == KEY_W)
		sprite_for_w(param, frame, sprites);
	if (direction == KEY_A)
		sprite_for_a(param, frame, sprites);
	if (direction == KEY_S)
		sprite_for_s(param, frame, sprites);
	if (direction == KEY_D)
		sprite_for_d(param, frame, sprites);
	mlx_put_image_to_window(
		param->mlx, param->win, sprites->current, x * 64, y * 64);
}
