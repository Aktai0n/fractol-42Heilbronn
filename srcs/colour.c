/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:24:43 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/30 13:38:55 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	colour_pixel(int i, t_data *data)
{
	int		colour[3];
	int		colourmode[3];
	double	i_ratio;
	double	i_ratio_rec;

	i_ratio = (double)i / (double)data->colour.max_i;
	i_ratio_rec = 1 - i_ratio;
	ft_bzero(colour, sizeof(colour));
	colourmode[0] = 0b000000111000111111111 & data->colour.mode;
	if (colourmode[0] != 0)
		colour[data->colour.offset % 3]
			= 9 * (i_ratio * i_ratio * i_ratio) * i_ratio_rec * 255;
	colourmode[1] = 0b000111000111000111111 & data->colour.mode;
	if (colourmode[1] != 0)
		colour[(1 + data->colour.offset) % 3]
			= 15 * (i_ratio * i_ratio) * (i_ratio_rec * i_ratio_rec) * 255;
	colourmode[2] = 0b111000000111111000111 & data->colour.mode;
	if (colourmode[2] != 0)
		colour[(2 + data->colour.offset) % 3]
			= 9 * i_ratio * (i_ratio_rec * i_ratio_rec * i_ratio_rec) * 255;
	return (0 << 24 | colour[0] << 16 | colour[1] << 8 | colour[2]);
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
