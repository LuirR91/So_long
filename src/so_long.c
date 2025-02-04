/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:34 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:44 by luiribei         ###   ########.fr       */
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
	t_g	g;

	ft_bzero(&g, sizeof(t_g));
	if (argc == 2)
	{
		g.mlx = mlx_init();
		g.map = map_read(argv[1], &g);
		g.map_copy = map_read(argv[1], &g);
		mlx_get_screen_size(g.mlx, &g.screen_width, &g.screen_height);
		if (check_argv(argv[1]) && check_map(&g))
		{
			g_init(&g);
			gplay(&g);
			mlx_loop(g.mlx);
		}
		else
			print_error("Invalid map.", &g);
	}
	else
		ft_printf("Bad syntax:\n./so_long ./maps/<map>.ber.\n");
	return (0);
}

/* valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
--log-file=valgrind-out.txt */
