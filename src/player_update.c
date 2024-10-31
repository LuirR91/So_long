/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:22 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/28 18:14:26 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	player_img_update(char key, t_game *game)
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
	player_img_update('w', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_c == 0)
	{
		game->map[game->y_player + 1][game->x_player] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1' || \
		game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_c -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

void	s_key(t_game *game)
{
	player_img_update('s', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_c == 0)
	{
		game->map[game->y_player - 1][game->x_player] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1' || \
		game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_c -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

void	a_key(t_game *game)
{
	player_img_update('a', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_c == 0)
	{
		game->map[game->y_player][game->x_player + 1] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1' || \
		game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_c -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

void	d_key(t_game *game)
{
	player_img_update('d', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_c == 0)
	{
		game->map[game->y_player][game->x_player - 1] = '0';
		game->finish = 1;
		print_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1' || \
		game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_c -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		ft_printf("%d\n", game->moves);
		draw_game(game);
	}
}

/* 
void	w_key(t_game *game)
{
	player_update_image('w', game);
	game->moves++;
	ft_printf("%d\n", game->moves);
	draw_game(game);
}

void	s_key(t_game *game)
{
	player_update_image('s', game);
	game->moves++;
	ft_printf("%d\n", game->moves);
	draw_game(game);
}

void	d_key(t_game *game)
{
	player_update_image('d', game);
	game->moves++;
	ft_printf("%d\n", game->moves);
	draw_game(game);
}

void	a_key(t_game *game)
{
	player_update_image('a', game);
	game->moves++;
	ft_printf("%d\n", game->moves);
	draw_game(game);
} */
