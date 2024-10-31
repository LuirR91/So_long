/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:02 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/28 18:05:02 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	game_events(int	keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		game->y_player -= SPEED;
		w_key(game);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		game->y_player += SPEED;
		s_key(game);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		game->x_player -= SPEED;
		d_key(game);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		game->x_player += SPEED;
		a_key(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == XK_q)
	{
		ft_printf("Cant beat the game? srsly?\n");
		exit_game(game);
	}
	else if (!game->finish)
		game_events(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
