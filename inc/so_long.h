/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:50 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/21 17:01:16 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	height;
	int	width;
}		t_window;

t_window	new_program(int w, int h, char *str);

#endif
