#include "../inc/so_long.h"

static void	game_events(int	keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		write(1, "w\n", 2);
		game->y_player -= SPEED;
		w_key(game);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		write(1, "s\n", 2);
		game->y_player += SPEED;
		s_key(game);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		write(1, "a\n", 2);
		game->x_player -= SPEED;
		d_key(game);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		write(1, "d\n", 2);
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
	//mlx_clear_window(game->mlx, game->win);
	game_events(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
