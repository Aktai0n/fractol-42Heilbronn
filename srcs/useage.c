/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:27:22 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:30:14 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_incorrect_useage(void)
{
	printf("\nIncorrect useage\n");
	printf("\nto use the program, type:\n");
	printf("	./fractol 1			to display the mandelbrot set\n");
	printf("	./fractol 2 X.X X.X		to display the julia set*\n");
	printf("	./fractol 3			to display the tricorn set\n");
	printf("	./fractol 4			to display the burning ship set\n");
	printf("\n		*the two floats are the real and imaginary\n");
	printf("		starting coordinates of the julia set\n");
	printf("		and therefore determine the shape of it\n\n");
	exit(EXIT_FAILURE);
}

void	print_useage(void)
{
	printf("\nUseage of the window:\n");
	printf("\nKeyboard:\n");
	printf("	arrow keys:		move in the x and y direction\n");
	printf("	page up / down:		change colour sceme\n");
	printf("	num + and -:		increase / decrease the accuracy\n");
	printf("	num 1 to 4:		change the fractol to\n");
	printf("	1) mandelbrot	2) julia	3) tricorn	4) burning ship\n");
	printf("\nMouse:\n");
	printf("	mouse wheel:		zoom in and out\n");
	printf("	left mouse button:	click & release to move around\n");
	printf("	right mouse button:	switch to the julia set and display it\n");
	printf("				corresponding to the position of the mouse\n\n");
}
