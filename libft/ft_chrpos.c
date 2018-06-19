/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:21:12 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/07 16:21:32 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_chrpos(char *str, char c)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (str[i] && str[i] != c)
	{
		counter++;
		i++;
	}
	if (str[counter] == c)
		return (counter);
	else
		return (-1);
}
