/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:33 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/28 18:03:16 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_argv(char *argv)
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

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc == 2)
	{
		game.mlx = mlx_init();
		game.map = map_read(argv[1], &game);
		game.map_copy = map_read(argv[1], &game);
		mlx_get_screen_size(game.mlx, &game.screen_width, &game.screen_height);
		if (check_argv(argv[1]) && check_map(&game))
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
			print_error("Invalid map.", &game);
	}
	else
		ft_printf("Bad syntax:\n./so_long ./maps/<map>.ber.\n");
	return (0);
}


//	MAC		cc main.c minilibx_mac/libmlx.a -framework AppKit -framework OpenGL
//	LINUX	cc -Wall -Wextra -Werror main.c minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz
//	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
