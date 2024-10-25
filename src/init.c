#include "../inc/so_long.h"

/* static void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->map[0]) * 64;
	while (game->map[i])
		i++;
	game->map_heigth = i * 64;
} */

static void	img_init(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
		PLAYER_FRONT_XPM, &game->img_width, &game->img_height);
}

void	game_init(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDHT, HEIGHT, "so long");
	img_init(game);
	draw_game(game);
}
