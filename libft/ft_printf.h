/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:28:27 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/02 16:32:03 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Includes
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** Prototypes
*/

int	ft_printf(const char *format, ...);
int	ft_format_args(const char *format, va_list *args);
int	ft_putnbr_printf(int n);
int	ft_putchar_printf(int c);
int	ft_putstr_printf(char *s);
int	ft_putnbr_base(unsigned long x, char *charset, unsigned int base);
int	ft_putaddr(void *addr);

#endif