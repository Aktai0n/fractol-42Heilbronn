/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:06:28 by skienzle          #+#    #+#             */
/*   Updated: 2021/09/12 10:48:27 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*sub_str;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && (i + start) < str_len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
