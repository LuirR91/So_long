/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:15:23 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:53:30 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	player_img_update(char key, t_g *g)
{
	mlx_destroy_image(g->mlx, g->img_player);
	if (key == 'w')
		g->img_player = mlx_xpm_file_to_image
			(g->mlx, PLAYER_BACK_XPM, &g->img_width, &g->img_height);
	else if (key == 's')
		g->img_player = mlx_xpm_file_to_image
			(g->mlx, PLAYER_FRONT_XPM, &g->img_width, &g->img_height);
	else if (key == 'a')
		g->img_player = mlx_xpm_file_to_image
			(g->mlx, PLAYER_LEFT_XPM, &g->img_width, &g->img_height);
	else if (key == 'd')
		g->img_player = mlx_xpm_file_to_image
			(g->mlx, PLAYER_RIGHT_XPM, &g->img_width, &g->img_height);
}

void	w_key(t_g *g)
{
	player_img_update('w', g);
	if (g->map[g->yp][g->xp] == 'E' && g->n_c == 0)
	{
		g->map[g->yp + 1][g->xp] = '0';
		g->finish = 1;
		print_win(g);
	}
	else if (g->map[g->yp][g->xp] == '1' || g->map[g->yp][g->xp] == 'E')
	{
		g->yp += 1;
		draw_g(g);
	}
	else
	{
		g->map[g->yp + 1][g->xp] = 'F';
		if (g->map[g->yp][g->xp] == 'C')
		{
			g->n_c -= 1;
			g->map[g->yp + 1][g->xp] = 'K';
		}
		g->map[g->yp][g->xp] = 'P';
		g->moves++;
		ft_printf("%d\n", g->moves);
		draw_g(g);
	}
}

void	s_key(t_g *g)
{
	player_img_update('s', g);
	if (g->map[g->yp][g->xp] == 'E' && g->n_c == 0)
	{
		g->map[g->yp - 1][g->xp] = '0';
		g->finish = 1;
		print_win(g);
	}
	else if (g->map[g->yp][g->xp] == '1' || g->map[g->yp][g->xp] == 'E')
	{
		g->yp -= 1;
		draw_g(g);
	}
	else
	{
		g->map[g->yp - 1][g->xp] = 'F';
		if (g->map[g->yp][g->xp] == 'C')
		{
			g->n_c -= 1;
			g->map[g->yp - 1][g->xp] = 'K';
		}
		g->map[g->yp][g->xp] = 'P';
		g->moves++;
		ft_printf("%d\n", g->moves);
		draw_g(g);
	}
}

void	a_key(t_g *g)
{
	player_img_update('a', g);
	if (g->map[g->yp][g->xp] == 'E' && g->n_c == 0)
	{
		g->map[g->yp][g->xp + 1] = '0';
		g->finish = 1;
		print_win(g);
	}
	else if (g->map[g->yp][g->xp] == '1' || g->map[g->yp][g->xp] == 'E')
	{
		g->xp += 1;
		draw_g(g);
	}
	else
	{
		g->map[g->yp][g->xp + 1] = 'F';
		if (g->map[g->yp][g->xp] == 'C')
		{
			g->n_c -= 1;
			g->map[g->yp][g->xp + 1] = 'K';
		}
		g->map[g->yp][g->xp] = 'P';
		g->moves++;
		ft_printf("%d\n", g->moves);
		draw_g(g);
	}
}

void	d_key(t_g *g)
{
	player_img_update('d', g);
	if (g->map[g->yp][g->xp] == 'E' && g->n_c == 0)
	{
		g->map[g->yp][g->xp - 1] = '0';
		g->finish = 1;
		print_win(g);
	}
	else if (g->map[g->yp][g->xp] == '1' || g->map[g->yp][g->xp] == 'E')
	{
		g->xp -= 1;
		draw_g(g);
	}
	else
	{
		g->map[g->yp][g->xp - 1] = 'F';
		if (g->map[g->yp][g->xp] == 'C')
		{
			g->n_c -= 1;
			g->map[g->yp][g->xp - 1] = 'K';
		}
		g->map[g->yp][g->xp] = 'P';
		g->moves++;
		ft_printf("%d\n", g->moves);
		draw_g(g);
	}
}
