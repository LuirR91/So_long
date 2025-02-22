/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:16:06 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:44 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	verify_nl(char *line, char *map_tmp, t_g *g)
{
	if (line && *line == '\n')
	{
		free(line);
		free(map_tmp);
		print_error("New line in map.", g);
	}
}

char	**map_read(char *path, t_g *g)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_tmp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_tmp = ft_strdup("");
	while (true)
	{
		line = get_next_line(fd);
		verify_nl(line, map_tmp, g);
		if (!line)
			break ;
		tmp = map_tmp;
		map_tmp = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	map = ft_split(map_tmp, '\n');
	free(map_tmp);
	close(fd);
	return (map);
}
