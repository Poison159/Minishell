/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:45:49 by tmaske            #+#    #+#             */
/*   Updated: 2016/07/25 16:39:46 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	char *d;

	d = (char*)ft_memalloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	d = ft_strcpy(d, s);
	return (d);
}
