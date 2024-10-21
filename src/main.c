#include "../inc/so_long.h"

int	main()
{
	t_win	program;
	program = new_program(900, 900, "hey");
	if (!program.mlx_ptr || !program.win_ptr)
		return (1);

	t_img	image;
	image = new_img(300, 300, program);
	mlx_destroy_image(program.mlx_ptr, image.img_ptr);

	/* ft_printf ("Let's find out what's inside our structure \n");
	ft_printf ("img_ptr			: [%p]\n", image.img_ptr);
	ft_printf ("bpp			: [%d]\n", image.bpp);
	ft_printf ("line_len		: [%d]\n", image.line_len);
	ft_printf ("endian			: [%d]\n", image.endian);
	ft_printf ("addr			: [%d]\n", image.addr); */

	mlx_loop(program.mlx_ptr);
	return (0);
}


//	MAC		cc main.c minilibx_mac/libmlx.a -framework AppKit -framework OpenGL
//	LINUX	cc -Wall -Wextra -Werror main.c minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz
