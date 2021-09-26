/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:21:40 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:19:31 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

double	Re_to_x(double Re, t_data *data)
{
	double	real_x;
	double	x;

	real_x = (Re / data->coords.range_Re) * WINDOW_WIDTH;
	x = real_x + data->coords.origin_Re;
	return (x);
}

double	Im_to_y(double Im, t_data *data)
{
	double	imaginary_y;
	double	y;

	imaginary_y = (Im / data->coords.range_Im) * WINDOW_HEIGHT * -1;
	y = imaginary_y + data->coords.origin_Im;
	return (y);
}
