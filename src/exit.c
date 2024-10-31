/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:43 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/28 18:13:16 by luiribei         ###   ########.fr       */
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

int	exit_game(t_game *game)
{
	free_map(game->map);
	free_map(game->map_copy);
	mlx_destroy_image(game->mlx, game->img_collectable);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	print_error(char *str, t_game *game)
{
	if (game->map)
	{
		free_map(game->map);
		free_map(game->map_copy);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	print_win(t_game *game)
{
	ft_printf("\n========================================\n");
	ft_printf("   You finish the game with %d moves   ", game->moves);
	ft_printf("\n========================================\n");
	exit_game(game);
}
