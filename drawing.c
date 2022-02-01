#include "raycast.h"

void pix_to_img(t_data *data, int x, int y, int color)
{
	char *addr;

	printf("got x %d y %d\n", x, y);
	printf("got ll %d bpp %d\n", data->line_length, data->bits_per_pixel);
	addr = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	printf("got address");
	*(unsigned int *)addr = color;
	printf("drew color");
}

void get_new_image(void **new, t_window *win)
{
	*new = mlx_new_image(win->mlx, WIN_X, WIN_Y);
	win->img->addr = mlx_get_data_addr(*new, &(win->img->bits_per_pixel),
								&(win->img->line_length), &(win->img->endian));
}