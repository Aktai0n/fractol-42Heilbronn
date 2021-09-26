/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:49:31 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:46:58 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Includes
*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/ft_printf.h"
# include "structures.h"
# include "keycodes.h"

/*
** Prototypes
*/

double	ft_atof(const char *str);


void	init_struct(int argc, char **argv, t_data *data);

void	choose_fractal(int argc, char **argv, t_data *data);

void	handle_c_julia(char **argv, t_data *data);


int		colour_pixel(int A, int R, int G, int B);

int		colour_shade(int i, t_data *data);

void	colour_shift(int keycode, t_data *data);


double	x_to_Re(double x, t_data *data);

double	y_to_Im(double y, t_data *data);

double	Re_to_x(double Re, t_data *data);

double	Im_to_y(double Im, t_data *data);


int		create_image(t_data *data);

int		pixel_loop(t_data *data);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int colour);

int		destroy_window(t_data *data);


int		key_hook(int keycode, t_data *data);

void	arrow_keys(int keycode, t_data *data);

int		mouse_press(int keycode, int x, int y, t_data *data);

void	mouse_scroll(int keycode, int x, int y, t_data *data);

int		mouse_release(int keycode, int x, int y, t_data *data);

int		mouse_pos(int x, int y, t_data *data);


void	print_incorrect_useage(void);

void	print_useage(void);


int		mandelbrot(t_data *data);

int		julia(t_data *data);

int		tricorn(t_data *data);

int		burningship(t_data *data);

/*
** Defines
*/

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280

# define ON 1
# define OFF 0

#endif