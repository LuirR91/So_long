#include "so_long.h"

int	exit_program (t_img	*img)
{
	if (img)
	{
		if (img->win)
			free(img->win);
		free(img);
	}
	exit(EXIT_SUCCESS);
}
