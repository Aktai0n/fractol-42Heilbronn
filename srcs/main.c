/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:10:44 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:10:20 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atof(const char *str)
{
	double	num;
	double	exp;
	double	index;
	int		i;

	i = 0;
	index = 1.0;
	num = 0.0;
	exp = 0.1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			index = -1.0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		num = num * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = num + ((str[i++] - '0') * exp);
		exp *= 0.1;
	}
	return (index * num);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		print_incorrect_useage();
	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
	init_struct(argc, argv, &data);
	create_image(&data);
	print_useage();
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_hook(data.mlx_window, 17, 0, destroy_window, &data);
	mlx_hook(data.mlx_window, 4, 0, mouse_press, &data);
	mlx_hook(data.mlx_window, 5, 0, mouse_release, &data);
	mlx_hook(data.mlx_window, 6, 0, mouse_pos, &data);
	mlx_loop(data.mlx);
	return (0);
}

void	print_incorrect_useage()
{
	printf("\nIncorrect useage\n");
	printf("\nto use the program, type:\n");
	printf("	./fractol 1			to display the mandelbrot set\n");
	printf("	./fractol 2 X.X X.X		to display the julia set*\n");
	printf("	./fractol 3			to display the tricorn set\n");
	printf("	./fractol 4			to display the burning ship set\n");
	printf("\n		*the two floats are the real and imaginary starting coordinates\n");
	printf("		of the julia set and therefore determine the shape of it\n\n");
	exit(EXIT_FAILURE);
}

void	print_useage()
{
	printf("\nUseage of the window:\n");
	printf("\nKeyboard:\n");
	printf("	arrow keys:		move in the x and y direction\n");
	printf("	page up / down:		change colour sceme\n");
	printf("	num + and -:		increase / decrease the accuracy of the image\n");
	printf("	num 1 to 4:		change the fractol to\n");
	printf("	1) mandelbrot	2) julia	3) tricorn	4) burning ship\n");
	printf("\nMouse:\n");
	printf("	mouse wheel:		zoom in and out\n");
	printf("	left mouse button:	click & release to move in the x and y direction\n");
	printf("	right mouse button:	switch to the julia set and display it\n");
	printf("				corresponding to the position of the mouse\n\n");
}
