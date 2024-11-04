/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:16:10 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/04 11:56:34 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	flood_fill(t_game *game, int y, int x, char visit)
{
	get_win_size(game);
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width \
		|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == visit)
		return ;
	if (game->map_copy[y][x] == 'C')
		game->map_copy[y][x] = '0';
	if (game->map_copy[y][x] == 'E')
	{
		game->map_copy[y][x] = visit;
		return ;
	}
	game->map_copy[y][x] = visit;
	flood_fill(game, y + 1, x, visit);
	flood_fill(game, y - 1, x, visit);
	flood_fill(game, y, x + 1, visit);
	flood_fill(game, y, x - 1, visit);
}

static void	ft_pl_pos(t_game *game, int *pl_y, int *pl_x)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (game->map_copy[y][x] == 'P')
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

static void	check_ce(t_game *game)
{
	int	y;
	int	x;

	game->n_vc = 0;
	game->n_ve = 0;
	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (game->map_copy[y][x] == 'C')
				game->n_vc++;
			if (game->map_copy[y][x] == 'E')
				game->n_ve++;
			x++;
		}
		y++;
	}
}

static void	put_exit_wall(t_game *game, int *y, int *x)
{
	int	col;
	int	row;

	row = 0;
	while (game->map_copy[row])
	{
		col = 0;
		while (game->map_copy[row][col])
		{
			if (game->map_copy[row][col] == 'E')
			{
				game->map_copy[row][col] = '1';
				*y = row;
				*x = col;
				break ;
			}
			col++;
		}
		row++;
	}
}

int	check_win(t_game *game)
{
	int	pl_x;
	int	pl_y;
	int	e_x;
	int	e_y;

	pl_x = 0;
	pl_y = 0;
	e_x = 0;
	e_y = 0;
	ft_pl_pos(game, &pl_y, &pl_x);
	put_exit_wall(game, &e_y, &e_x);
	flood_fill(game, pl_y, pl_x, 'X');
	game->map_copy[e_y][e_x] = 'E';
	flood_fill(game, pl_y, pl_x, 'V');
	check_ce(game);
	if (game->n_vc != 0 || game->n_ve != 0)
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

 */
