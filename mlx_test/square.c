#include <mlx.h>
#include <stdio.h>

#define WIN_Y 400
#define WIN_X 600
#define SIDE 20

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		x0;
	int		y0;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

int	rush(int key, t_data *img)
{
	printf("got key %d\n", key);
	if (key == 65362)
		img->y0 -= 5;
	else if (key == 65361)
		img->x0 -= 5;
	else if (key == 65364)
		img->y0 += 5;
	else if (key == 65363)
		img->x0 += 5;
	redraw(img);
	return (0);
}

int	main(void)
{
	t_data img;

	img.x0 = 290;
	img.y0 = 190;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIN_X, WIN_Y, "square");
	img.img = mlx_new_image(img.mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								&img.line_length, &img.endian);
	redraw(&img);
	mlx_hook (img.win, 2, 1L << 0, rush, &img);
	mlx_loop(img.mlx);
}
