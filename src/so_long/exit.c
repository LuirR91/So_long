/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:49 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 13:56:37 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	int	len;

	len = 0;
	while (map[len])
	{
		free(map[len]);
		len++;
	}
	free(map);
}

int	exit_g(t_g *g)
{
	free_map(g->map);
	free_map(g->map_copy);
	mlx_destroy_image(g->mlx, g->img_collectable);
	mlx_destroy_image(g->mlx, g->img_collectable_kill);
	mlx_destroy_image(g->mlx, g->img_player);
	mlx_destroy_image(g->mlx, g->img_wall);
	mlx_destroy_image(g->mlx, g->img_floor);
	mlx_destroy_image(g->mlx, g->img_floor_update);
	mlx_destroy_image(g->mlx, g->img_exit);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
	return (0);
}

void	print_error(char *str, t_g *g)
{
	if (g->map)
	{
		free_map(g->map);
		free_map(g->map_copy);
	}
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	print_win(t_g *g)
{
	ft_printf("\n========================================\n");
	ft_printf("   Gratz!! Finished with %d moves   ", g->moves);
	ft_printf("\n========================================\n");
	exit_g(g);
}
