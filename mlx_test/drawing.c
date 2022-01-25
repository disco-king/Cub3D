#include "square.h"

void pix_to_img(t_data *data, int x, int y, int color)
{
	char *addr;

	addr = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)addr = color;
}

int draw_square(int x, int y, t_data *img)
{
	int ver = 0;
	int hor;

	while(ver < WIN_Y)
	{
		hor = 0;
		while (hor < WIN_X)
		{
			if(hor > x && hor < x + SIDE
				&& ver > y && ver < y + SIDE)
				pix_to_img(img, hor, ver, 0x00FF0000);
			else
				pix_to_img(img, hor, ver, 0x000000FF);
			hor++;
		}
		ver++;
	}
	return(0);
}

int redraw(t_data *img)
{
	void *new;

	new = mlx_new_image(img->mlx, WIN_X, WIN_Y);
	img->addr = mlx_get_data_addr(new, &(img->bits_per_pixel),
								&(img->line_length), &(img->endian));
	draw_square(img->x0, img->y0, img);
	mlx_put_image_to_window(img->mlx, img->win, new, 0, 0);
	return(0);
}
