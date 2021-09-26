/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:51:06 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/26 20:51:21 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
