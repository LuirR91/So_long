/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:16:01 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:44 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_rectangle(t_g *g)
{
	int	len;

	len = 1;
	if (!g->map)
		return (0);
	get_win_size(g);
	while (g->map[len])
	{
		if (ft_strlen(g->map[len]) != ft_strlen(g->map[0]))
			return (0);
		len++;
	}
	return (1);
}

static int	check_close(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x] != '\0' || map[y - 1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	x = ft_strlen(map[y]);
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_pce(t_g *g)
{
	int	y;
	int	x;

	g->n_c = 0;
	g->n_e = 0;
	g->n_p = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x] != '\0')
		{
			if (g->map[y][x] == 'P')
				g->n_p++;
			else if (g->map[y][x] == 'C')
				g->n_c++;
			else if (g->map[y][x] == 'E')
				g->n_e++;
			x++;
		}
		y++;
	}
	if (g->n_p != 1 || g->n_e != 1 || g->n_c == 0)
		return (0);
	return (1);
}

static int	check_valid(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C' && \
				map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_g *g)
{
	if (check_rectangle(g) && check_close(g->map) && check_pce(g) && \
		check_valid(g->map) && check_win(g))
		return (1);
	else if (!check_rectangle(g))
		print_error("Map is not rectangle.", g);
	else if (!check_close(g->map))
		print_error("Map is not closed.", g);
	else if (!check_pce(g))
		print_error("PCE not valid.", g);
	else if (!check_valid(g->map))
		print_error("Invalid map. Only P, C, E, 1, 0 allowed.", g);
	else if (!check_win(g))
		print_error("The map is not winable", g);
	return (0);
}

/*

<<<<<<<<<<<<		MAP			>>>>>>>>>>>>

	    x[0] |  x[1] |  x[2] |  x[3] |  x[4]

y[0]   [0,0] | [0,1] | [0,2] | [0,3] | [0,4]
y[1]   [1,0] | [1,1] | [1,2] | [1,3] | [1,4]
y[2]   [2,0] | [2,1] | [2,2] | [2,3] | [2,4]
y[3]   [3,0] | [3,1] | [3,2] | [3,3] | [3,4]
y[4]   [4,0] | [4,1] | [4,2] | [4,3] | [4,4]

 */
