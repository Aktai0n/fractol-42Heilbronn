/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:06:00 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/02 14:10:45 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(int c)
{
	int	ret;

	ret = write(1, &c, 1);
	return (ret);
}

int	ft_putstr_printf(char *s)
{
	int	i;

	if (s == NULL)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long x, char *charset, unsigned int base)
{
	unsigned long	n;
	int				ret;

	ret = 0;
	if (x >= base)
		ret += ft_putnbr_base(x / base, charset, base);
	n = x % base;
	ret += write(1, charset + n, 1);
	return (ret);
}

int	ft_putnbr_printf(int n)
{
	unsigned int	num;
	char			write_n;
	int				ret;

	ret = 0;
	if (n < 0)
	{
		ret += write(1, "-", 1);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ret += ft_putnbr_printf(num / 10);
	write_n = (num % 10) + '0';
	ret += write(1, &write_n, 1);
	return (ret);
}
