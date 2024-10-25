#include "../inc/so_long.h"

static void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_BACK_XPM, &game->img_width, &game->img_height);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_LEFT_XPM, &game->img_width, &game->img_height);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, PLAYER_RIGHT_XPM, &game->img_width, &game->img_height);
}

void	w_key(t_game *game)
{
	player_update_image('w', game);
	draw_game(game);
}

void	s_key(t_game *game)
{
	player_update_image('s', game);
	draw_game(game);
}

void	d_key(t_game *game)
{
	player_update_image('d', game);
	draw_game(game);
}

void	a_key(t_game *game)
{
	player_update_image('a', game);
	draw_game(game);
}
