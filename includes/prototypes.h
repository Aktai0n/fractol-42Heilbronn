/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:00:55 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/30 14:48:52 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/* Initializing the variables for the coords, colour, fract and mouse structs */
void	init_struct(int argc, char **argv, t_data *data);

/* Choosing the fractal that's displayed when the window is opened, based on
** the number specified in argv[2] and checking for the right number of args */
void	choose_fractal(int argc, char **argv, t_data *data);

/* If the julia fractial is displayed first, the starting values of x_Re and
** x_Im specified in argv[2] and argv[3] are checked and converted to double */
void	handle_c_julia(char **argv, t_data *data);

/* The colour of each pixel is calculated based on the ratio of iterations to
** maximal iterations and its reciprocal */
int		colour_pixel(int i, t_data *data);

/* The colourmode is determined from a pool of 21 possible modes */
void	colour_shift(int keycode, t_data *data);

/* Converting the x coordinate on the window to a real coordinate in the
** coordinate system of the fractol */
double	x_to_Re(double x, t_data *data);

/* Converting the y coordinate on the window to a imaginary coordinate in the
** coordinate system of the fractol */
double	y_to_Im(double y, t_data *data);

/* Converting the real coordinate in the coordinate system of the fractol
** to a x coordinate on the window */
double	Re_to_x(double Re, t_data *data);

/* Converting the imaginary coordinate in the coordinate system of the fractol
** to a y coordinate on the window */
double	Im_to_y(double Im, t_data *data);

/* Creating a new image, getting the image address and pushing it to the screen
** after the pixels have been coloured */
void	create_image(t_data *data);

/* Looping over every pixel of the screen, applying the specified fractol
** to each pixel and getting the colour of that pixel */
void	pixel_loop(t_data *data);

/* The selfmade version of mlx_pixel_put. Sets the colour to the correct
** pixel in the x and y position of the screen */
void	ft_mlx_pixel_put(t_data *data, int x, int y, int colour);

/* Closing the current image and window so the program exits properly */
int		destroy_window(t_data *data);

/* Will be called through mlx_key_hook each time a key is pressed.
** Performs or redirects the functions associated to the keys */
int		key_hook(int keycode, t_data *data);

/* Extension of the key_hook because of moulinette */
void	arrow_keys(int keycode, t_data *data);

/* Will be called through mlx_hook with mode 4 -> Is called every time
** a mouse key is pressed and perfoms the asscoiated actions */
int		mouse_press(int keycode, int x, int y, t_data *data);

/* Zooming into or out of the window (onto the current position of the
** mouse cursor) */
void	mouse_scroll(int keycode, int x, int y, t_data *data);

/* Will be called through mlx_hook with mode 5 -> Is called every time
** a mouse key is released and perfoms the click-to-navigate action */
int		mouse_release(int keycode, int x, int y, t_data *data);

/* Will be called through mlx_hook with mode 6 -> Is called every time
** the mouse is moved and modifies the julia set according to the mouse
** position if the mode is activated */
int		mouse_pos(int x, int y, t_data *data);

/* Prints instructions on how to get the parameters should be specified
** if incorrect parameters are given */
void	print_incorrect_useage(void);

/* Prints instructions on how to use fract-ol when it's opened */
void	print_useage(void);

/* The formula of the mandelbrot set */
int		mandelbrot(t_data *data);

/* The formula of the julia set */
int		julia(t_data *data);

/* The formula of the tricorn set */
int		tricorn(t_data *data);

/* The formula of the burningship set */
int		burningship(t_data *data);

#endif