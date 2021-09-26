/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:43:17 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:45:57 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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

#endif