#include "../inc/so_long.h"

void	draw_square(t_square square, t_img *img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i < img->h)
	{
		j = 0;
		while (j < square.size && j < img->w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

int	main()
{
	t_window	*win;
	t_img		*img;

	win = new_window(1080, 1920, "hhey");
	if (!win)
		return (-1);
	img = new_image(win, 1080, 1920);
	if (!img)
		return (-1);
	//draw_square((t_square){0, 0, 300, 0x00FFFF}, img);
	//mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	mlx_hook(win->win_ptr, 2, 1L<<0, continuous_read_keys, img);
	mlx_key_hook (win->win_ptr, read_keys, img);
    mlx_mouse_hook (win->win_ptr, read_mouse, img);
	mlx_hook(win->win_ptr, 17, 0, exit_program, img);
	mlx_hook(win->win_ptr, 6, 0, follow_mouse, img);

	mlx_loop(win->mlx_ptr);
	free(win);
	free(img);
	return (0);
}


//	MAC		cc main.c minilibx_mac/libmlx.a -framework AppKit -framework OpenGL
//	LINUX	cc -Wall -Wextra -Werror main.c minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz

	/* ft_printf ("Let's find out what's inside our structure \n");
	ft_printf ("img_ptr			: [%p]\n", image.img_ptr);
	ft_printf ("bpp			: [%d]\n", image.bpp);
	ft_printf ("line_len		: [%d]\n", image.line_len);
	ft_printf ("endian			: [%d]\n", image.endian);
	ft_printf ("addr			: [%d]\n", image.addr); */
