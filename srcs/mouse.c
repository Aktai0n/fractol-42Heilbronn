/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:29:53 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:38:03 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_scroll(int keycode, int x, int y, t_data *data)
{
	double	start_Re;
	double	start_Im;
	double	end_Re;
	double	end_Im;

	start_Re = x_to_Re((double)x, data);
	start_Im = y_to_Im((double)y, data);
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
	end_Re = x_to_Re((double)x, data);
	end_Im = y_to_Im((double)y, data);
	data->coords.origin_Re = Re_to_x(end_Re - start_Re, data);
	data->coords.origin_Im = Im_to_y(end_Im - start_Im, data);
}

int	mouse_press(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_DOWN_KEYCODE || keycode == MOUSE_UP_KEYCODE)
		mouse_scroll(keycode, x, y, data);
	if (keycode == MOUSE_RIGHT_KEYCODE && data->fract.get_mouse_pos == OFF)
	{
		data->fract.get_mouse_pos = ON;
		data->fract.c_Re = x_to_Re((double)x, data);
		data->fract.c_Im = y_to_Im((double)y, data);
		data->fract.fract_type = julia;
	}
	else if (keycode == MOUSE_RIGHT_KEYCODE && data->fract.get_mouse_pos == ON)
		data->fract.get_mouse_pos = OFF;
	if (keycode == MOUSE_LEFT_KEYCODE)
	{
		data->mouse.press_Re = x_to_Re((double)x, data);
		data->mouse.press_Im = y_to_Im((double)y, data);
		return (0);
	}
	create_image(data);
	return (0);
}

int	mouse_pos(int x, int y, t_data *data)
{
	if (data->fract.get_mouse_pos == ON)
	{
		data->fract.c_Re = x_to_Re((double)x, data);
		data->fract.c_Im = y_to_Im((double)y, data);
		data->fract.fract_type = julia;
		create_image(data);
	}
	return (0);
}

int	mouse_release(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_LEFT_KEYCODE)
	{
		data->mouse.release_Re = x_to_Re((double)x, data);
		data->mouse.release_Im = y_to_Im((double)y, data);
		data->coords.origin_Re
			= Re_to_x(data->mouse.release_Re - data->mouse.press_Re, data);
		data->coords.origin_Im
			= Im_to_y(data->mouse.release_Im - data->mouse.press_Im, data);
		create_image(data);
	}
	return (0);
}
