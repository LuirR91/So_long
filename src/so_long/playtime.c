/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:39 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:44 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	events(int keycode, t_g *g)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		g->yp -= 1;
		w_key(g);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		g->yp += 1;
		s_key(g);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		g->xp -= 1;
		a_key(g);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		g->xp += 1;
		d_key(g);
	}
}

static int	ft_keycode(int keycode, t_g *g)
{
	if (keycode == XK_Escape)
	{
		ft_printf("You din't finish the g :(\n");
		exit_g(g);
	}
	else if (!g->finish)
		events(keycode, g);
	return (0);
}

void	gplay(t_g *g)
{
	mlx_hook(g->win, 2, 1L << 0, ft_keycode, g);
	mlx_hook(g->win, 17, 1L << 17, exit_g, g);
}
