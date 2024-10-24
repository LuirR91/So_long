#include "../inc/so_long.h"

/* static void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game->map_w = ft_strlen(game->map[0]) * 32;
	while (game->map[i])
		i++;
	game->map_h = i * 32;
} */

static void	img_init(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so long");
	game->moves = 0;
	game->endgame = 0;
	img_init(game);
}
