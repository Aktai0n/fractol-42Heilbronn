/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:25:52 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:18:07 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
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
			data->coords.Re = x_to_Re((double)x_pos, data);
			data->coords.Im = y_to_Im((double)y_pos, data);
			iterations = data->fract.fract_type(data);
			colour = colour_shade(iterations, data);
			ft_mlx_pixel_put(data, x_pos, y_pos, colour);
			y_pos++;
		}
		x_pos++;
	}
	return (0);
}

int	create_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
	pixel_loop(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
	return (0);
}

int	destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_window);
	exit(EXIT_SUCCESS);
}
