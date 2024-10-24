#include "../inc/so_long.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv [i - 3] == '.')
		return (1);
	return (0);
}

int	main()
{
	t_game	game;

	game_init(&game);
	gameplay(&game);

	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}


//	MAC		cc main.c minilibx_mac/libmlx.a -framework AppKit -framework OpenGL
//	LINUX	cc -Wall -Wextra -Werror main.c minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz
