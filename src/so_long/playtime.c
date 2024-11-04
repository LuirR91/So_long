/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:39 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/03 15:20:21 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	events(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		game->y_player -= 1;
		w_key(game);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		game->y_player += 1;
		s_key(game);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		game->x_player -= 1;
		a_key(game);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		game->x_player += 1;
		d_key(game);
	}
}

static int	ft_keycode(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("You din't finish the game :(\n");
		exit_game(game);
	}
	else if (!game->finish)
		events(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, ft_keycode, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
