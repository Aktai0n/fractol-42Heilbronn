/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:49:31 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 12:07:51 by skienzle         ###   ########.fr       */
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
} t_fractol;

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
}	t_data;



/*
** Prototypes
*/



/*
** Defines
*/

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280

# define ESC_KEYCODE 53
# define W_KEYCODE 13
# define A_KEYCODE 0
# define S_KEYCODE 1
# define D_KEYCODE 2
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