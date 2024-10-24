#include "../inc/so_long.h"

static void	game_events(int	keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
	{
		game->y_player -= SPEED;
		player_w(game);
	}
	else if (keycode == S || keycode == DOWN)
	{
		game->y_player += SPEED;
		player_s(game);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		game->x_player += SPEED;
		player_d(game);
	}
	else if (keycode == A || keycode == LEFT)
	{
		game->x_player -= SPEED;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->moves);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
