#include "square.h"

int	rush(t_data *img)
{
	if (img->up)
		img->y0 -= 5;
	if (img->left)
		img->x0 -= 5;
	if (img->down)
		img->y0 += 5;
	if (img->right)
		img->x0 += 5;
	redraw(img);
	return (0);
}

int move_handler(int key, t_data *img)
{
	if (key == 65362)
		img->up = 1;
	if (key == 65361)
		img->left = 1;
	if (key == 65364)
		img->down = 1;
	if (key == 65363)
		img->right = 1;
	return(rush(img));
}

int stop_handler(int key, t_data *img)
{
	if (key == 65362)
		img->up = 0;
	if (key == 65361)
		img->left = 0;
	if (key == 65364)
		img->down = 0;
	if (key == 65363)
		img->right = 0;
	return(rush(img));
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
	mlx_hook (img.win, 2, 1L << 0, move_handler, &img);
	mlx_hook (img.win, 3, 1L << 1, stop_handler, &img);
	mlx_loop (img.mlx);
}
