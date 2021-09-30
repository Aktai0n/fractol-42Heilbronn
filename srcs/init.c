/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:22:56 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/30 13:41:33 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_c_julia(char **argv, t_data *data)
{
	int	errors[2];
	int	i;
	int	j;

	j = 2;
	while (j < 4)
	{
		ft_bzero(errors, sizeof(errors));
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (ft_strchr("+-.0123456789", argv[j][i]) == NULL)
				print_incorrect_useage();
			if (argv[j][i] == '+' || argv[j][i] == '-')
				errors[0]++;
			if (argv[j][i] == '.')
				errors[1]++;
			i++;
		}
		if (errors[0] > 1 || errors[1] > 1)
			print_incorrect_useage();
		j++;
	}
	data->fract.c_Re = ft_atof(argv[2]);
	data->fract.c_Im = ft_atof(argv[3]);
}

void	choose_fractal(int argc, char **argv, t_data *data)
{
	int		fract_type;

	fract_type = ft_atoi(argv[1]);
	if (fract_type > 4 || fract_type < 1
		|| (fract_type == 1 && argc != 2)
		|| (fract_type == 2 && argc != 4)
		|| (fract_type == 3 && argc != 2)
		|| (fract_type == 4 && argc != 2))
		print_incorrect_useage();
	if (fract_type == 1)
		data->fract.fract_type = mandelbrot;
	else if (fract_type == 2)
		data->fract.fract_type = julia;
	else if (fract_type == 3)
		data->fract.fract_type = tricorn;
	else if (fract_type == 4)
		data->fract.fract_type = burningship;
	if (fract_type == 2)
		handle_c_julia(argv, data);
	else
	{
		data->fract.c_Re = 0.0;
		data->fract.c_Im = 0.0;
	}
}

void	init_struct(int argc, char **argv, t_data *data)
{
	choose_fractal(argc, argv, data);
	data->fract.get_mouse_pos = OFF;
	data->coords.range_Im = 2.0;
	data->coords.range_Re = 3.5;
	data->coords.origin_Im = WINDOW_HEIGHT / 2.0;
	data->coords.origin_Re = WINDOW_WIDTH / 2.0;
	data->coords.Im = 0.0;
	data->coords.Re = 0.0;
	data->colour.offset = 0;
	data->colour.max_i = 50;
	data->colour.mode = 1;
	data->mouse.press_Re = 0.0;
	data->mouse.press_Im = 0.0;
	data->mouse.release_Re = 0.0;
	data->mouse.release_Im = 0.0;
}
