#include "raycast.h"

void pix_to_img(t_data *data, int x, int y, int color)
{
	char *addr;

	addr = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)addr = color;
}

void get_new_image(void **new, t_window *win)
{
	*new = mlx_new_image(win->mlx, WIN_X, WIN_Y);
	win->img->addr = mlx_get_data_addr(new, &(win->img->bits_per_pixel),
								&(win->img->line_length), &(win->img->endian));
}