/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:27:38 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:20:53 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_data *data)
{
	double	temp;
	double	temp_Re;
	double	temp_Im;
	int		i;

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

int	julia(t_data *data)
{
	double	temp;
	double	temp_Re;
	double	temp_Im;
	int		i;

	temp_Re = data->coords.Re;
	temp_Im = data->coords.Im;
	i = 0;
	while (i < data->colour.max_i && pow(temp_Re, 2) + pow(temp_Im, 2) <= 4)
	{
		temp = pow(temp_Re, 2) - pow(temp_Im, 2) + data->fract.c_Re;
		temp_Im = 2 * temp_Re * temp_Im + data->fract.c_Im;
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
	int		i;

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
	int		i;

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
