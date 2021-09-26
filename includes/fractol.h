/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:49:31 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 19:43:20 by skienzle         ###   ########.fr       */
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
# include "mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/ft_printf.h"

/*
** Structures
*/

typedef struct s_complex
{
	double	range_Re;
	double	range_Im;
	double	origin_Re;
	double	origin_Im;
	double	Re;
	double	Im;
}	t_complex;

typedef struct s_colour
{
	int		max_i;
	int		offset;
	int		mode;
}	t_colour;

typedef struct s_fractol
{
	double	c_Re;
	double	c_Im;
	int		get_mouse_pos;
	int		(*fract_type)();
}	t_fractol;

typedef struct s_mouse
{
	double	press_Re;
	double	press_Im;
	double	release_Re;
	double	release_Im;
}	t_mouse;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	t_complex	coords;
	t_colour	colour;
	t_fractol	fract;
	t_mouse		mouse;
}	t_data;



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

int		mouse_press(int keycode, int x, int y, t_data *data);

void	mouse_scroll(int keycode, int x, int y, t_data *data);

int		mouse_release(int keycode, int x, int y, t_data *data);

int		mouse_pos(int x, int y, t_data *data);


void	print_incorrect_useage();

void	print_useage();


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

# define ESC_KEYCODE 53
# define UP_KEYCODE 126
# define DOWN_KEYCODE 125
# define LEFT_KEYCODE 123
# define RIGHT_KEYCODE 124
# define NUM_1_KEYCODE 83
# define NUM_2_KEYCODE 84
# define NUM_3_KEYCODE 85
# define NUM_4_KEYCODE 86
# define NUM_PLUS_KEYCODE 69
# define NUM_MINUS_KEYCODE 78
# define PAGE_UP_KEYCODE 116
# define PAGE_DOWN_KEYCODE 121

# define MOUSE_LEFT_KEYCODE 1
# define MOUSE_RIGHT_KEYCODE 2
# define MOUSE_MIDDLE_KEYCODE 3
# define MOUSE_UP_KEYCODE 4
# define MOUSE_DOWN_KEYCODE 5

#endif