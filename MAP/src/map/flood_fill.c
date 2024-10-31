#include "../inc/so_long.h"

static void	flood_fill(t_game *game, int x, int y, char visit)
{
	get_win_size(game);
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height \
		|| game->map_copy[x][y] == '1' || game->map_copy[x][y] == visit)
		return ;
	if (game->map_copy[x][y] == 'C')
		game->map_copy[x][y] = '0';
	if (game->map_copy[x][y] == 'E')
	{
		game->map_copy[x][y] = visit;
		return ;
	}
	game->map_copy[x][y] = visit;
	flood_fill(game, x + 1, y, visit);
	flood_fill(game, x - 1, y, visit);
	flood_fill(game, x, y + 1, visit);
	flood_fill(game, x, y - 1, visit);
}

static void	player_pos(t_game *game, int *player_x, int *player_y)
{
	int	x;
	int	y;

	x = 0;
	while (game->map_copy[x])
	{
		y = 0;
		while (game->map_copy[x][y])
		{
			if (game->map_copy[x][y] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return (0);
			}
			y++;
		}
		x++;
	}
}

static void	check_ce(t_game *game)
{
	int	x;
	int y;

	game->n_vc = 0;
	game->n_ve = 0;
	x = 0;
	while (game->map_copy[x])
	{
		y = 0;
		while (game->map_copy[x][y])
		{
			if (game->map_copy[x][y] == 'C')
				game->n_vc++;
			if (game->map_copy[x][y] == 'E')
				game->n_ve++;
			y++;
		}
		x++;
	}
}

static void	put_exit_wall (t_game *game, int *y, int *x)
{
	int	col;
	int	row;

	col = 0;
	while (game->map_copy[col])
	{
		row = 0;
		while (game->map_copy[col][row])
		{
			if (game->map_copy[col][row] == 'E')
			{
				game->map_copy[col][row] == '1';
				*x = col;
				*y = row;
				return (0);
			}
			row++;
		}
		col++;
	}
}

int	check_win(t_game *game)
{
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;

	player_x = 0;
	player_y = 0;
	exit_x = 0;
	exit_y = 0;
	ft_player_position(game, &player_x, &player_y);
	put_exit_wall(game, &exit_x, &exit_y);
	flood_fill(game, player_x,  player_y, 'X');
	game->map_copy[exit_x][exit_y] = 'E';
	flood_fill(game, player_x,  player_y, 'V');
	check_ce(game);
	if (game->n_vc != 0 || game->n_ve != 0)
		return (1);
	return (0);
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
