/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/21 17:44:11 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	height;
	int	width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int	h;
	int	w;
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;

// Functions

t_win	new_program(int w, int h, char *str);
t_img	new_img(int w, int h, t_win	window);

#endif
