/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:33:21 by tmaske            #+#    #+#             */
/*   Updated: 2016/12/20 17:59:25 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	endl_count(char *buff, t_line **li)
{
	t_line *lj;

	lj = *li;
	lj->cnt = 0;
	lj->i = 0;
	while (buff[lj->i])
	{
		if (buff[lj->i] == '\n' && lj->i != 0)
			lj->cnt++;
		lj->i++;
	}
	if (lj->cnt > 0)
	{
		lj->i = 0;
		while (buff[lj->i] != '\n')
			lj->i++;
	}
	else if ((ft_strlen(buff) == 1 && buff[0] == '\n') || ft_strlen(buff) == 0)
		lj->cnt = -1;
}

void	retemp(char **temp)
{
	char *tmp;

	if (*temp != NULL)
	{
		if (ft_strlen(*temp) > 1)
		{
			tmp = (char*)ft_memalloc(ft_strlen(*temp) * sizeof(char));
			ft_strcpy(tmp, *temp + 1);
			ft_strdel(temp);
			*temp = tmp;
		}
		else if (ft_strlen(*temp) == 1 && ft_strcmp(*temp, "\n") == 0)
			ft_strdel(temp);
	}
}

void	mvr(char ***line, char **temp, t_line *li)
{
	endl_count(*temp, &li);
	if (li->cnt == -1)
	{
		li->ret = 0;
		ft_strdel(temp);
	}
	else if (li->cnt == 0 && ft_strlen(*temp) > 0 && li->red < BUFF_SIZE)
	{
		**line = (char*)ft_memalloc((ft_strlen(*temp) + 1) * sizeof(char));
		ft_strcpy(**line, *temp);
		ft_strdel(temp);
		*temp = NULL;
	}
	else if (li->cnt > 0)
	{
		**line = ft_strsub(*temp, 0, (size_t)li->i);
		li->found = (char*)ft_memalloc((ft_strlen(
			ft_strchr(*temp, '\n')) + 1) * sizeof(char));
		ft_strcpy(li->found, ft_strchr(*temp, '\n'));
		ft_strdel(temp);
		*temp = li->found;
	}
}

void	rdr(const int fd, t_line *li, char **temp)
{
	char		buff[BUFF_SIZE + 1];
	char		*newtemp;

	li->red = read(fd, buff, BUFF_SIZE);
	buff[li->red] = '\0';
	if (li->red == -1)
		li->ret = -1;
	else if (li->red == 0 && (*temp == NULL || ft_strcmp(*temp, "") == 0))
		li->ret = 0;
	else if (li->red >= 1)
	{
		if (*temp != NULL && ft_strcmp(*temp, "") != 0)
		{
			newtemp = ft_strjoin(*temp, buff);
			ft_strdel(temp);
			*temp = newtemp;
		}
		else
			*temp = ft_strdup(buff);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*temp = "";
	t_line		li;

	li.red = BUFF_SIZE;
	li.found = NULL;
	li.ret = 1;
	while (li.found == NULL && li.red == BUFF_SIZE)
	{
		rdr(fd, &li, &temp);
		if (li.ret == 1)
			mvr(&line, &temp, &li);
	}
	if (temp != NULL && temp[0] == '\n')
		retemp(&temp);
	return (li.ret);
}
