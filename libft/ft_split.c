/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skienzle <skienzle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:05:35 by skienzle          #+#    #+#             */
/*   Updated: 2021/08/21 16:43:59 by skienzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_cpy_word(char const *s, char c, int *i)
{
	int		j;
	int		len;
	char	*sub_str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (0);
	j = 0;
	while (j < len)
	{
		sub_str[j] = s[j];
		j++;
	}
	sub_str[j] = '\0';
	*i += len;
	return (sub_str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**splits;

	if (!s)
		return (0);
	splits = (char **)malloc(sizeof(splits) * (ft_words(s, c) + 1));
	if (!splits)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			splits[j] = ft_cpy_word(s + i, c, &i);
			j++;
		}
		else
			i++;
	}
	splits[j] = 0;
	return (splits);
}
