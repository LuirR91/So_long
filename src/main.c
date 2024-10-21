#include "../inc/so_long.h"

int	main()
{
	t_window	window;
	window = new_program(900, 900, "hey");
	if (!window.mlx_ptr || !window.win_ptr)
		return (1);
	mlx_loop(window.mlx_ptr);
	return (0);
}


//	MAC		cc main.c minilibx_mac/libmlx.a -framework AppKit -framework OpenGL
//	LINUX	cc -Wall -Wextra -Werror main.c minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz
