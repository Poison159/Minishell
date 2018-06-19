/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:29:13 by tmaske            #+#    #+#             */
/*   Updated: 2016/07/18 17:50:42 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_atoi_max(const char *nptr, int **r)
{
	int					counter;
	unsigned long long	done;
	int					flag;

	done = 0;
	counter = 0;
	flag = 0;
	if (nptr[0] == '-')
		flag++;
	while (nptr[counter] != '\0')
	{
		if (nptr[counter] > 47 && nptr[counter] < 58)
			done = ((done * 10) + nptr[counter]) - '0';
		counter++;
	}
	if (done / 4294967296 < 1)
	{
		if (flag == 1)
			done = done * -1;
		**r = (int)done;
	}
	else
		*r = NULL;
}
