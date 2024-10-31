/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:21 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/28 18:11:31 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	screen_size_init(t_game *game)
{
	int	y;

	game->map_width = ft_strlen(game->map[0]) * 64;
	y = 0;
	while (game->map[y])
		y++;
	game->map_height = y * 64;
	if (game->map_width > game->screen_width || \
		game->map_height > game->screen_height)
		print_error("Map is too big for the screen.", game);
}

static void	img_init(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		WALL_XPM, &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		FLOOR_XPM, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, \
		COLLECTABLE_XPM, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
		EXIT_CLOSED_XPM, &game->img_width, &game->img_height);
}

void	game_init(t_game *game)
{
	screen_size_init(game);
	game->win = mlx_new_window(game->mlx, game->map_width, \
		game->map_height, "so_long");
	game->moves = 0;
	game->finish = 0;
	img_init(game);
	draw_game(game);
}
