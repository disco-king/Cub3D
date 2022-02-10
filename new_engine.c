#include "raycast.h"

void	choose_color(t_window *window)
{
	if (window->side == 0)
	{
		if (window->player->y > window->player->dir_y)
			window->color += 200;
	}
	if (window->side == 1)
	{
		if (window->player->x > window->player->dir_x)
			window->color -= 200;
	}
}

float	fix_angle(float angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	check_borders(t_window *window)
{
	int	mx;
	int	my;
	int	mp;

	mx = (int)window->player->dir_x;
	my = (int)window->player->dir_y;
	mp = my * window->x_border + mx;
	//printf("mp is %d %d\n", mp, window->x_border * window->y_border);
	// if (mx > window->x_border || my > window->y_border)
	// 	return (0);
	if (mp > 0 && mp < window->x_border * window->y_border)
		return (1);
	return (0);
}

void	new_engine_start(t_window *window)
{
	float	r;
	float	user_tan;
	float	step_x;
	float	step_y;
	float	distance_vert;
	float	distance_hor;
	float	v_x;
	float	v_y;
	int		hit;
	int		x;
	int		i;
	void	*image;
	t_data img;

	window->img = &img;
	i = 0;
	step_x = 0;
	step_y = 0;
	hit = 0;
	r = window->player->angle;
	//printf("%f\n", window->player->angle);
	r += M_PI / 6;
	r = fix_angle(r);
	x = 0;
	distance_vert = 100000;
	distance_hor = 100000;
	// get_new_image(&image, window);
	// if(!image || !window->img->addr)
	// {
	// 	printf("init returned NULL\n");
	// 	exit(1);
	// }
	//color_window(window);
	while (x < 1280)
	{
		distance_vert = 100000;
		distance_hor = 100000;
		window->color = 160000;
		user_tan = tan(r);
		window->side = 0;
		//printf("distance vert is %f user_tan in vertical is %f and r is %f\n",distance_vert, user_tan, r);
		if (cos(r) > 0.001)
		{
			window->player->dir_x = window->player->x + 1;
			window->player->dir_y = (window->player->x - window->player->dir_x)
				* user_tan + window->player->y;
			step_x = 1;
			step_y = -step_x * user_tan;
		}
		else if (cos(r) < -0.001)
		{
			window->player->dir_x = window->player->x - 0.0001;
			window->player->dir_y = (window->player->x - window->player->dir_x)
				* user_tan + window->player->y;
			step_x = -1;
			step_y = -step_x * user_tan;
			//printf("here dir_x %f dir_y %f step_x %f step_y %f\n",
				//window->player->dir_x, window->player->dir_y, step_x, step_y);
		}
		else
		{
			window->player->dir_x = window->player->x;
			window->player->dir_y = window->player->y;
			hit = 1;
		}
		i = 0;
		while (!hit && i <= window->x_border)
		{
			//printf("nearest wall %d %d \n", (int)window->player->dir_x, (int)window->player->dir_y);
			// printf("char is %c\n", window->map[(int)window->player->dir_y][(int)window->player->dir_x]);
			if (check_borders(window))
				if (window->player->dir_x < 0 || window->player->dir_y < 0
					|| window->map[(int)window->player->dir_y][(int)window->player->dir_x] == '1')
				{
					distance_vert = cos(r) * (window->player->dir_x - window->player->x)
						- sin(r) * (window->player->dir_y - window->player->y);
					//printf("here %f\n", distance_vert);
					hit = 1;
				}
			if (!hit)
			{
				i++;
				window->player->dir_x += step_x;
				window->player->dir_y += step_y;
				//distance_vert = 100000;
			}
		}
		//printf("i is %d\n", i);
		i = 0;
		v_x = window->player->dir_x;
		v_y = window->player->dir_y;
		user_tan = 1 / user_tan;
		hit = 0;
		//printf("distance vert is %f user_tan in horizontal is %f\n", distance_vert, user_tan);
		// printf("direction after vert %f %f\n",window->player->dir_x, window->player->dir_y);
		if (sin(r) > 0.001)
		{
			window->player->dir_y = window->player->y - 0.0001;
			window->player->dir_x = (window->player->y - window->player->dir_y)
				* user_tan + window->player->x;
			step_y = -1;
			step_x = -step_y * user_tan;
		}
		else if (sin(r) < -0.001)
		{
			window->player->dir_y = window->player->y + 1;
			window->player->dir_x = (window->player->y - window->player->dir_y)
				* user_tan + window->player->x;
			step_y = 1;
			step_x = -step_y * user_tan;
		}
		else
		{
			window->player->dir_x = window->player->x;
			window->player->dir_y = window->player->y;
			hit = 1;
		}
		i = 0;
		while (!hit && i <= window->y_border)
		{
			//printf("dir_x %f dir_y %f \n",window->player->dir_x, window->player->dir_y);
			if (check_borders(window))
				if (window->player->dir_x < 0 || window->player->dir_y < 0
					|| window->map[(int)window->player->dir_y][(int)window->player->dir_x] == '1')
				{
					distance_hor = cos(r) * (window->player->dir_x - window->player->x)
						- sin(r) * (window->player->dir_y - window->player->y);
					hit = 1;
				}
			// else
			// {
			if (!hit)
			{
				i++;
				window->player->dir_x += step_x;
				window->player->dir_y += step_y;
				//distance_hor = 100000;
			}
		}

		// printf("direction after hor %f %f\n",window->player->dir_x, window->player->dir_y);
		//printf("distance hor %f is distance vert is %f\n", distance_hor, distance_vert);
		if (distance_vert < distance_hor)
		{
			//printf("distance vert has been chosen\n");
			window->player->dir_x = v_x;
			window->player->dir_y = v_y;
			window->distance = distance_vert;
			window->color = 160100;
			window->side = 1;
		}
		else
			window->distance = distance_hor;
		// window->camera_angle = window->player->angle - r;
		// window->camera_angle = fix_angle(window->camera_angle);
		window->distance = cos(r - window->player->angle) * window->distance;
		//printf("r is %f\n", r);
		choose_color(window);
		//printf("color is %d\n",window->color);
		draw_wall(window, x);
		x += 1;
		r -= M_PI / 3 / 1280;
		r = fix_angle(r);
		hit = 0;
	}
	//mlx_put_image_to_window(window->mlx, window->window, image, 0, 0);
	//write(1, "here\n", 5);
	// printf("angle change %f\n", M_PI / 3 / 1280);
	// printf("angle is %f dir_x %f dir_y %f step_x is %f step_y is %f tan is %f\n", r, window->player->dir_x, window->player->dir_y, step_x, step_y, user_tan);
	// printf("x is %f y is %f\n", window->player->x, window->player->y);
			//printf("x is %d\n", x);
}
