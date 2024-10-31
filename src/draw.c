/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:19 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/28 18:12:52 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

static void	put_player(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	put_image(game, image, x, y);
}

static void	put_exit(t_game *game, int x, int y)
{
	if(game->n_c == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx, \
			EXIT_OPEN_XPM, &game->img_width, &game->img_height);
	}
	put_image(game, game->img_exit, x ,y);
}

int	draw_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				put_image(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				put_image(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->img_collectable, x, y);
			else if (game->map[y][x] == 'P')
				put_player(game, game->img_player, x, y);
			else if (game->map[y][x] == 'E')
				put_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

