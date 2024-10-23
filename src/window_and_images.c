#include "../inc/so_long.h"

t_game	*new_game(int height, int width, char *str)
{
	t_game	*win;
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (NULL);
	win_ptr = mlx_new_game (mlx_ptr, width, height, str);
	if (!win_ptr)
		return (NULL);
	win = (t_game *)malloc(sizeof(t_game));
	win->mlx = mlx_ptr;
	win->win = win_ptr;
	win->height = height;
	win->width = width;
	return (win);
}

t_image	*new_image(t_game *game, int height, int width)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->game = game;
	img->w = width;
	img->h = height;
	img->img_ptr = mlx_new_image (game->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_len), &(img->endian));
	return (img);
}
