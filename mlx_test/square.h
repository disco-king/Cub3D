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
	int		up;
	int		down;
	int		left;
	int		right;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void pix_to_img(t_data *data, int x, int y, int color);
int draw_square(int x, int y, t_data *img);
int redraw(t_data *img);
