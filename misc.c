#include "so_long.h"

void	print_tile(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, x * 64, y * 64);
}
