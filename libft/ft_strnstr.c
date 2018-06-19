/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:25:11 by tmaske            #+#    #+#             */
/*   Updated: 2016/11/16 18:19:55 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *hy, const char *needle, size_t len)
{
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(needle);
	if (len2 == 0)
		return ((char*)hy);
	while (hy[i] && len2 <= len--)
	{
		if (ft_memcmp(hy + i, needle, len2) == 0)
			return ((char *)hy + i);
		i++;
	}
	return (NULL);
}
