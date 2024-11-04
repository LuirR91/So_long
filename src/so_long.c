/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:34 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/04 14:31:21 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_argv(char	*argv)
{
	int	len;

	if (!argv)
		return (0);
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' && \
		argv[len - 3] == '.')
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

/* valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
--log-file=valgrind-out.txt */
