/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:08:30 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/12 15:47:22 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *addr)
{
	unsigned long	nbr_addr;
	int				ret;

	nbr_addr = (unsigned long)addr;
	ret = write(1, "0x", 2);
	ret += ft_putnbr_base(nbr_addr, "0123456789abcdef", 16);
	return (ret);
}

int	ft_format_args(const char *format, va_list *args)
{
	int	ret;

	ret = 0;
	if (*format == '%')
		ret += ft_putchar_printf('%');
	else if (*format == 'c')
		ret += ft_putchar_printf(va_arg(*args, int));
	else if (*format == 's')
		ret += ft_putstr_printf(va_arg(*args, char *));
	else if (*format == 'd' || *format == 'i')
		ret += ft_putnbr_printf(va_arg(*args, int));
	else if (*format == 'u')
		ret += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789", 10);
	else if (*format == 'x')
		ret += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef", 16);
	else if (*format == 'X')
		ret += ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF", 16);
	else if (*format == 'p')
		ret += ft_putaddr(va_arg(*args, void *));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_format_args(format + i, &args);
			i++;
		}
		else
		{
			ret += ft_putchar_printf(format[i]);
			i++;
		}
	}
	va_end(args);
	return (ret);
}
