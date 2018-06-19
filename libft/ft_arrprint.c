/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:22:40 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/07 16:22:42 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_arrprint(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putendl(arr[i]);
		i++;
	}
}
