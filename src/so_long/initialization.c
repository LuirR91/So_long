/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:44 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/04 14:31:06 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_img(t_game *game)
{
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		FLOOR_XPM, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		WALL_XPM, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, \
		COLLECTABLE_XPM, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
		EXIT_CLOSED_XPM, &game->img_width, &game->img_height);
}

void	get_win_size(t_game *game)
{
	int	x;

	game->map_width = ft_strlen(game->map[0]) * 64;
	x = 0;
	while (game->map[x])
		x++;
	game->map_height = x * 64;
	if (game->map_width > game->screen_width || \
		game->map_height > (game->screen_height - 64))
		print_error("Map is too big for the screen.", game);
}

void	game_init(t_game *game)
{
	get_win_size(game);
	game->win = mlx_new_window(game->mlx, game->map_width, \
		game->map_height, "so_long");
	game->moves = 0;
	game->finish = 0;
	init_img(game);
	draw_game(game);
}
