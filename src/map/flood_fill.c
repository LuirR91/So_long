/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:16:10 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:44 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	flood_fill(t_g *g, int y, int x, char visit)
{
	get_win_size(g);
	if (y < 0 || x < 0 || y >= g->map_height || x >= g->map_width \
		|| g->map_copy[y][x] == '1' || g->map_copy[y][x] == visit)
		return ;
	if (g->map_copy[y][x] == 'C')
		g->map_copy[y][x] = '0';
	if (g->map_copy[y][x] == 'E')
	{
		g->map_copy[y][x] = visit;
		return ;
	}
	g->map_copy[y][x] = visit;
	flood_fill(g, y + 1, x, visit);
	flood_fill(g, y - 1, x, visit);
	flood_fill(g, y, x + 1, visit);
	flood_fill(g, y, x - 1, visit);
}

static void	ft_pl_pos(t_g *g, int *pl_y, int *pl_x)
{
	int	y;
	int	x;

	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (g->map_copy[y][x] == 'P')
			{
				*pl_y = y;
				*pl_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
}

static void	check_ce(t_g *g)
{
	int	y;
	int	x;

	g->n_vc = 0;
	g->n_ve = 0;
	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (g->map_copy[y][x] == 'C')
				g->n_vc++;
			if (g->map_copy[y][x] == 'E')
				g->n_ve++;
			x++;
		}
		y++;
	}
}

int	check_win(t_g *g)
{
	int	pl_x;
	int	pl_y;
	int	e_x;
	int	e_y;

	pl_x = 0;
	pl_y = 0;
	e_x = 0;
	e_y = 0;
	ft_pl_pos(g, &pl_y, &pl_x);
	flood_fill(g, pl_y, pl_x, 'V');
	check_ce(g);
	if (g->n_vc != 0 || g->n_ve != 0)
		return (0);
	return (1);
}

/*

<<<		MAP		>>>

1 1 1 1 1 1 1 1 1 1
1 P 0 0 0 0 0 0 0 1
1 0 0 0 0 C 0 0 0 1
1 0 0 C 0 0 0 0 0 1
1 0 0 0 0 C 0 0 E 1
1 1 1 1 1 1 1 1 1 1

<<<		MAP		>>>

1 1 1 1 1 1 1 1 1 1
1 V V V V V V V V 1
1 V V V V V V V V 1
1 V V V V V V V V 1
1 V V V V V V V V 1
1 1 1 1 1 1 1 1 1 1

 */
