/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:10:44 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/30 16:06:45 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		print_incorrect_usage();
	init_struct(argc, argv, &data);
	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fract-ol");
	create_image(&data);
	print_usage();
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_hook(data.mlx_window, 17, 0, destroy_window, &data);
	mlx_hook(data.mlx_window, 4, 0, mouse_press, &data);
	mlx_hook(data.mlx_window, 5, 0, mouse_release, &data);
	mlx_hook(data.mlx_window, 6, 0, mouse_pos, &data);
	mlx_loop(data.mlx);
	return (0);
}
