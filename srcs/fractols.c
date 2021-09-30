/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:27:38 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/30 13:39:18 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_data *data)
{
	double	temp;
	double	x_Re;
	double	x_Im;
	double	pow_x;
	int		i;

	x_Re = 0.0;
	x_Im = 0.0;
	pow_x = 0.0;
	i = 0;
	while (i < data->colour.max_i && pow_x <= 4)
	{
		temp = x_Re * x_Re - x_Im * x_Im + data->coords.Re;
		x_Im = 2 * x_Re * x_Im + data->coords.Im;
		x_Re = temp;
		pow_x = x_Re * x_Re + x_Im * x_Im;
		i++;
	}
	return (i);
}

int	julia(t_data *data)
{
	double	temp;
	double	x_Re;
	double	x_Im;
	double	pow_x;
	int		i;

	x_Re = data->coords.Re;
	x_Im = data->coords.Im;
	pow_x = x_Re * x_Re + x_Im * x_Im;
	i = 0;
	while (i < data->colour.max_i && pow_x <= 4)
	{
		temp = x_Re * x_Re - x_Im * x_Im + data->fract.c_Re;
		x_Im = 2 * x_Re * x_Im + data->fract.c_Im;
		x_Re = temp;
		pow_x = x_Re * x_Re + x_Im * x_Im;
		i++;
	}
	return (i);
}

int	tricorn(t_data *data)
{
	double	temp;
	double	x_Re;
	double	x_Im;
	double	pow_x;
	int		i;

	x_Re = 0.0;
	x_Im = 0.0;
	pow_x = 0.0;
	i = 0;
	while (i < data->colour.max_i && pow_x <= 4)
	{
		temp = x_Re * x_Re - x_Im * x_Im + data->coords.Re;
		x_Im = -2 * x_Re * x_Im + data->coords.Im;
		x_Re = temp;
		pow_x = x_Re * x_Re + x_Im * x_Im;
		i++;
	}
	return (i);
}

int	burningship(t_data *data)
{
	double	temp;
	double	x_Re;
	double	x_Im;
	double	pow_x;
	int		i;

	x_Re = 0.0;
	x_Im = 0.0;
	pow_x = 0.0;
	i = 0;
	while (i < data->colour.max_i && pow_x <= 4)
	{
		temp = x_Re * x_Re - x_Im * x_Im + data->coords.Re;
		x_Im = fabs(2 * x_Re * x_Im) + data->coords.Im;
		x_Re = temp;
		pow_x = x_Re * x_Re + x_Im * x_Im;
		i++;
	}
	return (i);
}
