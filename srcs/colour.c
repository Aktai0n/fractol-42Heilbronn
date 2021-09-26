/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:24:43 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:22:32 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	int		colourmode[3];
	double	percent_i;

	percent_i = (double)i / (double)data->colour.max_i;
	ft_bzero(colour, sizeof(colour));
	colourmode[0] = 0b000000111000111111111 & data->colour.mode;
	if (colourmode[0] != 0)
		colour[data->colour.offset % 3]
			= 9 * pow(percent_i, 3) * (1 - percent_i) * 255;
	colourmode[1] = 0b000111000111000111111 & data->colour.mode;
	if (colourmode[1] != 0)
		colour[(1 + data->colour.offset) % 3]
			= 15 * pow(percent_i, 2) * pow(1 - percent_i, 2) * 255;
	colourmode[2] = 0b111000000111111000111 & data->colour.mode;
	if (colourmode[2] != 0)
		colour[(2 + data->colour.offset) % 3]
			= 9 * percent_i * pow(1 - percent_i, 3) * 255;
	return (colour_pixel(0, colour[0], colour[1], colour[2]));
}

void	colour_shift(int keycode, t_data *data)
{
	if (keycode == PAGE_UP_KEYCODE)
		data->colour.offset += 1;
	if (keycode == PAGE_DOWN_KEYCODE)
		data->colour.offset -= 1;
	if (data->colour.offset > 20)
		data->colour.offset = 0;
	if (data->colour.offset < 0)
		data->colour.offset = 20;
	data->colour.mode = 1 << data->colour.offset;
}
