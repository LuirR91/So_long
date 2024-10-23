#include "../inc/so_long.h"

int	main()
{
	t_game	*win;
	t_image		*img;

	win = new_window(1080, 1920, "hhey");
	if (!win)
		return (-1);
	img = new_image(win, 1080, 1920);
	if (!img)
		return (-1);
	mlx_key_hook (win->win, read_keys, img);
	mlx_mouse_hook (win->win, read_mouse, img);
	mlx_hook(win->win, 17, 0, exit_program, img);

	mlx_loop(win->mlx);
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
