/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:10:44 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/25 11:58:32 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int	init_struct(t_data *data)
{
	data->coords.range_Im = 2.0;
	data->coords.range_Re = 3.5;
	data->coords.origin_Im = WINDOW_HEIGHT / 2.0;
	data->coords.origin_Re = (WINDOW_WIDTH / 5.0) * 4.0;
	data->coords.Im = 0.0;
	data->coords.Re = 0.0;
	data->colour.offset = 0;
	data->colour.max_i = 100;
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	colour_pixel(int A, int R, int G, int B)
{
	if (A > 255)
		A = 0;
	if (R > 255)
		R = 0;
	if (G > 255)
		G = 0;
	if (B > 255)
		B = 0;
	return (A << 24 | R << 16 | G << 8 | B);
}

int	colour_shade(int i, t_data *data)
{
	int		colour[3];
	double	percent_i;
	
	percent_i = (double)i / (double)data->colour.max_i;
	colour[data->colour.offset] =
	9 * pow(percent_i, 3) * (1 - percent_i) * 255;
	colour[(1 + data->colour.offset) % 3] =
	15 * pow(percent_i, 2) * pow(1 - percent_i, 2) * 255;
	colour[(2 + data->colour.offset) % 3] =
	9 * percent_i * pow(1 - percent_i, 3) * 255;
	return (colour_pixel(0, colour[0], colour[1], colour[2]));
}

void	colour_shift(int keycode, t_data *data)
{
	if (keycode == RIGHT_KEYCODE)
		data->colour.offset += 1;
	if (keycode == LEFT_KEYCODE)
		data->colour.offset -= 1;
	if (data->colour.offset > 2)
		data->colour.offset = 0;
	if (data->colour.offset < 0)
		data->colour.offset = 2;
}

// Doesn't work properly
int julia(t_data *data)
{
	double	temp;
	double	temp_Re;
	double	temp_Im;
	double	c_Re;
	double	c_Im;
	int		i;

	// the c values have to be modifyable by the user
	c_Re = -0.4;
	c_Im = 0.6;
	temp_Re = data->coords.Re;
	temp_Im = data->coords.Im;
	i = 0;
	while (i < data->colour.max_i && pow(temp_Re, 2) + pow(temp_Im, 2) <= 4)
	{
		temp = pow(temp_Re, 2) + pow(temp_Im, 2) + c_Re;
		temp_Im = 2 * temp_Re * temp_Im + c_Im;
		temp_Re = temp;
		i++;
	}
	return (i);
}

int	mandelbrot(t_data *data)
{
	double	temp;
	double	temp_Re;
	double	temp_Im;
	int	i;

	temp_Re = 0.0;
	temp_Im = 0.0;
	i = 0;
	while (i < data->colour.max_i && pow(temp_Re, 2) + pow(temp_Im, 2) <= 4)
	{
		temp = pow(temp_Re, 2) - pow(temp_Im, 2) + data->coords.Re;
		temp_Im = 2 * temp_Re * temp_Im + data->coords.Im;
		temp_Re = temp;
		i++;
	}
	return (i);
}

int	tricorn(t_data *data)
{
	double	temp;
	double	temp_Re;
	double	temp_Im;
	int	i;

	temp_Re = 0.0;
	temp_Im = 0.0;
	i = 0;
	while (i < data->colour.max_i && pow(temp_Re, 2) + pow(temp_Im, 2) <= 4)
	{
		temp = pow(temp_Re, 2) - pow(temp_Im, 2) + data->coords.Re;
		temp_Im = -2 * temp_Re * temp_Im + data->coords.Im;
		temp_Re = temp;
		i++;
	}
	return (i);
}

int	burningship(t_data *data)
{
	double	temp;
	double	temp_Re;
	double	temp_Im;
	int	i;

	temp_Re = 0.0;
	temp_Im = 0.0;
	i = 0;
	while (i < data->colour.max_i && pow(temp_Re, 2) + pow(temp_Im, 2) <= 4)
	{
		temp = pow(temp_Re, 2) - pow(temp_Im, 2) + data->coords.Re;
		temp_Im = fabs(2 * temp_Re * temp_Im) + data->coords.Im;
		temp_Re = temp;
		i++;
	}
	return (i);
}
double	x_to_Re(double x, t_data *data)
{
	double	pixel_Re;
	double	Re;

	pixel_Re = x - data->coords.origin_Re;
	Re = (pixel_Re / WINDOW_WIDTH) * data->coords.range_Re;
	return (Re);
}

double	y_to_Im(double y, t_data *data)
{
	double	pixel_Im;
	double	Im;

	pixel_Im = y - data->coords.origin_Im;
	Im = (pixel_Im / WINDOW_HEIGHT) * data->coords.range_Im * -1;
	return (Im);
}

// Replaced by x_to_Re and y_to_Im due to the fact that this function
// is not useful for anyhing but the pixel loop
int	pixel_to_coords(double x_pos, double y_pos, t_data *data)
{
	double	pixel_Re;
	double	pixel_Im;

	pixel_Re = x_pos - data->coords.origin_Re;
	pixel_Im = y_pos - data->coords.origin_Im;

	data->coords.Re = (pixel_Re / WINDOW_WIDTH) * data->coords.range_Re;
	data->coords.Im = (pixel_Im / WINDOW_HEIGHT) * data->coords.range_Im * -1;
	return (mandelbrot(data));
	//return(julia(data));
}

int	pixel_loop(t_data *data)
{
	int	x_pos;
	int	y_pos;
	int	iterations;
	int	colour;

	x_pos = 0;
	while (x_pos < WINDOW_WIDTH)
	{
		y_pos = 0;
		while (y_pos < WINDOW_HEIGHT)
		{
			//iterations = pixel_to_coords((double)x_pos, (double)y_pos, data);
			data->coords.Re = x_to_Re((double)x_pos, data);
			data->coords.Im = y_to_Im((double)y_pos, data);
			//iterations = mandelbrot(data);
			//iterations = julia(data);
			//iterations = tricorn(data);
			iterations = burningship(data);
			colour = colour_shade(iterations, data);
			ft_mlx_pixel_put(data, x_pos, y_pos, colour);
			y_pos++;
		}
		x_pos++;
	}
	return (0);
}

int create_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	pixel_loop(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
	return (0);
}

int destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == W_KEYCODE)
		data->coords.origin_Im *= 1.1;
	if (keycode == S_KEYCODE)
		data->coords.origin_Im /= 1.1;
	if (keycode == A_KEYCODE)
		data->coords.origin_Re *= 1.1;
	if (keycode == D_KEYCODE)
		data->coords.origin_Re /= 1.1;
	if (keycode == UP_KEYCODE)
		data->colour.max_i += 10;
	if (keycode == DOWN_KEYCODE)
		data->colour.max_i -= 10;
	if (keycode == LEFT_KEYCODE || keycode == RIGHT_KEYCODE)
		colour_shift(keycode, data);
	if (keycode == ESC_KEYCODE)
		destroy_window(data);
	create_image(data);
	return (keycode);
}

// doesn't work because the keycode will always be MOUSE_LEFT_KEYCODE
// within this function. It's only updated in the main loop
int	mouse_left_click(int keycode, int x, int y, t_data *data)
{
	double	start_Re;
	double	start_Im;
	double	end_Re;
	double	end_Im;
	
	//start_Re = x_to_Re((double)x, data);
	//start_Im = y_to_Im((double)y, data);
	start_Re = x;
	start_Im = y;
	while (keycode == MOUSE_LEFT_KEYCODE)
	{
		printf("here\n");
	}
	//end_Re = x_to_Re((double)x, data);
	//end_Im = y_to_Im((double)y, data);
	end_Re = x;
	end_Im = y;
	data->coords.origin_Re += end_Re - start_Re;
	data->coords.origin_Im += end_Im - start_Im;
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_DOWN_KEYCODE)
	{
		data->coords.range_Im *= 1.1;
		data->coords.range_Re *= 1.1;
	}
	if (keycode == MOUSE_UP_KEYCODE)
	{
		data->coords.range_Re /= 1.1;
		data->coords.range_Im /= 1.1;
	}
	create_image(data);
	return (keycode);
}

int	main(void)
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
	init_struct(&data);
	create_image(&data);
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_mouse_hook(data.mlx_window, mouse_hook, &data);
	mlx_hook(data.mlx_window, 17, 0, destroy_window, &data);
	// does the same as the mlx_mouse_hook
	//mlx_hook(data.mlx_window, 4, 0, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}