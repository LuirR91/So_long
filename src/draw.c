#include "../inc/so_long.h"
/* 
static void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, game->img_player, x * 32, y * 32);
} */

/* static void	put_player(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	put_image(game, image, x, y);
} */

int	draw_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	//put_player(game->mlx, game->img_player, game->x_player, game->y_player);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->x_player, game->y_player);
	return (0);
}

