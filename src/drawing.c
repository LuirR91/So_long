#include "so_long.h"

int size = 200;
int follow = 0;

int get_color(int next)
{
	static int colors[8] = {0xFFFFFF, 0x0000FF, 0x00FF00, 0xFF0000, 0x00FFFF, 0xFF00FF, 0xFFFF00, 0x000000};
	static int count = 0;

	if (next)
		count = (count + 1) % 8;
	return colors[count];
}

int	read_keys(int key_pressed, void *param)
{
	t_img *img;

	img = (t_img *)param;
	if (key_pressed == XK_Return)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, img);
	else if (key_pressed == XK_Escape || !img)
		exit_program(img);
	else if (key_pressed == XK_f)
		follow = !follow;
	else if (key_pressed == XK_c)
		get_color(1);
	/* else if (key_pressed == PENGUIN)
		penguin(img);	 */
	else
		return (-1);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int	continuous_read_keys(int key_pressed, void *param)
{
	t_img *img;

	img = (t_img *)param;
	if (!img)
		exit_program(img);
	else if (key_pressed == XK_Up)
	{
		if (size <= img->w - 10)
			size+=10;
	}
	else if (key_pressed == XK_Down)
	{
		if (size >= 11)
			size-=10;
	}
	else if (key_pressed == XK_c)
		get_color(1);
	return (0);
}

int follow_mouse(int mouse_x, int mouse_y, void *param)
{
	int 		x;
	int 		y;
	t_img 		*img;
	t_square	s;

	img = (t_img *) param;
	if (!img)
		return (1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	if (!follow)
		return (3);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color(0)};
	draw_square(s, img);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	int 		x;
	int 		y;
	t_img 		*img;
	t_square	s;

	img = (t_img *) param;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color(0)};
	draw_square(s, img);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}

