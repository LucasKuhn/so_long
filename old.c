void draw_map(t_param	*param)
{
	int i;
	int j;
	i = 0;
	while (param->map[i])
	{
		j = 0;
		while(param->map[i][j])
		{
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
