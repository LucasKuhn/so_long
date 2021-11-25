print_wall(game, x, y)
{
	mlx_put_image_to_window(
			param->mlx, param->win, param->tile, param->x * 64, param->y * 64);
}
