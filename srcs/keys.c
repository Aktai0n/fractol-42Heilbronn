/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:37:21 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:40:03 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == UP_KEYCODE || keycode == DOWN_KEYCODE
		|| keycode == LEFT_KEYCODE || keycode == RIGHT_KEYCODE)
		arrow_keys(keycode, data);
	if (keycode == NUM_PLUS_KEYCODE)
		data->colour.max_i += 10;
	if (keycode == NUM_MINUS_KEYCODE)
		data->colour.max_i -= 10;
	if (keycode == NUM_1_KEYCODE)
		data->fract.fract_type = mandelbrot;
	if (keycode == NUM_2_KEYCODE)
		data->fract.fract_type = julia;
	if (keycode == NUM_3_KEYCODE)
		data->fract.fract_type = tricorn;
	if (keycode == NUM_4_KEYCODE)
		data->fract.fract_type = burningship;
	if (keycode == PAGE_UP_KEYCODE || keycode == PAGE_DOWN_KEYCODE)
		colour_shift(keycode, data);
	if (keycode == ESC_KEYCODE)
		destroy_window(data);
	create_image(data);
	return (0);
}

void	arrow_keys(int keycode, t_data *data)
{
	if (keycode == UP_KEYCODE)
		data->coords.origin_Im += WINDOW_HEIGHT * 0.05;
	if (keycode == DOWN_KEYCODE)
		data->coords.origin_Im -= WINDOW_HEIGHT * 0.05;
	if (keycode == LEFT_KEYCODE)
		data->coords.origin_Re += WINDOW_WIDTH * 0.05;
	if (keycode == RIGHT_KEYCODE)
		data->coords.origin_Re -= WINDOW_WIDTH * 0.05;
}
