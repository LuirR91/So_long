#include "../inc/so_long.h"

static int	check_rectangle(t_game *game)
{
	int	len;

	len = 1;
	if(!game->map)
		return (1);
	get_win_size(game);
	while (game->map[len])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[len]))
			return (1);
		len++;
	}
	return (0);
}

static int	check_close(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
		x++;
	while (map[0][y] || map[x - 1][y])
	{
		if (map[0][y] != '1' || map[x - 1][y] != '1')
			return (1);
		y++;
	}
	x = 1;
	y = ft_strlen(map[x]);
	while (map[x])
	{
		if (map[x][0] != '1' ||  map[x][y - 1] != '1')
			return (1);
		x++;
	}
	return (0);
}

static int	check_pce(t_game *game)
{
	int	x;
	int	y;

	game->n_c = 0;
	game->n_e = 0;
	game->n_p = 0;
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
				game->n_p++;
			else if (game->map[x][y] == 'C')
				game->n_c++;
			else if (game->map[x][y] == 'E')
				game->n_e++;
			y++;
		}
		x++;
	}
	if (game->n_p != 1 || game->n_c != 0 || game->n_e != 1)
		return (1);
	return (0);
}

static int	check_valid(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != 'P' && map[x][y] != 'E' && map[x][y] != 'C' \
				&& map[x][y] != '0' && map[x][y] != '1')
				return (1);
			y++;	
		}
		x++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	if (check_rectangle(game) &&  check_close(game->map) && check_pce(game->map) \
		&& check_valid(game->map))
		return (0);
	else if (!check_rectangle(game))
			print_error("Map is not rectangle.", game);
	else if (!check_close(game->map))
		print_error("Map is not closed.", game);
	else if (!check_pce(game))
		print_error("PCE not valid.", game);
	else if (!check_valid(game->map))
		print_error("Invalid map. Only P, C, E, 1, 0 characters are allowed.", game);
	else if (!check_win(game))
		print_error("Map is not winnable.", game);
	return (0);
}

/*

<<<<<<<<<<<<		MAP			>>>>>>>>>>>>

	    y[0] |  y[1] |  y[2] |  y[3] |  y[4]

x[0]   [0,0] | [0,1] | [0,2] | [0,3] | [0,4]
x[1]   [1,0] | [1,1] | [1,2] | [1,3] | [1,4]
x[2]   [2,0] | [2,1] | [2,2] | [2,3] | [2,4]
x[3]   [3,0] | [3,1] | [3,2] | [3,3] | [3,4]
x[4]   [4,0] | [4,1] | [4,2] | [4,3] | [4,4]

 */
