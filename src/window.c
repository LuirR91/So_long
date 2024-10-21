#include "../inc/so_long.h"

t_window	new_program(int w, int h, char *str)
{
	void *mlx_ptr;
	
	mlx_ptr = mlx_init();
	return ((t_window) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}
