/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:18:47 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/07 16:18:53 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_len_c_stop(const char *str, int start, char c)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && (str[start] != c))
	{
		start++;
		counter++;
	}
	return (counter);
}

static int		ft_split_count(char const *s, char c)
{
	int		flag;
	int		words;
	int		counter;
	int		len;
	char	*str;

	str = (char *)s;
	counter = 0;
	words = 0;
	len = ft_strlen(s);
	while (str[counter])
	{
		flag = 0;
		while (str[counter] != c && counter < len)
		{
			if (flag == 0)
			{
				flag = 1;
				words++;
			}
			counter++;
		}
		counter++;
	}
	return (words);
}

char			**ft_strsplitnum(char const *s, char c, int *words)
{
	int		i;
	int		counter;
	char	**arr;
	char	*str;

	i = 0;
	counter = 0;
	*words = ft_split_count(s, c);
	str = (char *)s;
	if (!str)
		return (NULL);
	arr = (char**)ft_memalloc(sizeof(char*) * (*words + 1));
	while (i < *words)
	{
		while ((str[counter] == c) && str[counter])
			counter++;
		arr[i] = ft_strsub(str, counter, ft_len_c_stop(str, counter, c));
		while ((str[counter] != c) && str[counter])
			counter++;
		i++;
	}
	arr[i] = "\0";
	return (arr);
}
