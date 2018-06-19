/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:20:29 by tmaske            #+#    #+#             */
/*   Updated: 2017/06/07 16:20:30 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_arrdel(char **arr)
{
	int		i;
	int		len;

	i = 0;
	if (arr == NULL)
		return ;
	len = ft_arrlen(arr);
	while (arr[i] != NULL && i < len)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr != NULL)
		free(arr);
	arr = NULL;
}
