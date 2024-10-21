#include "../inc/so_long.h"

t_img	new_img(int w, int h, t_win	window)
{
	t_img	image;
	
	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}
