/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:01:52 by tmaske            #+#    #+#             */
/*   Updated: 2016/08/28 17:59:50 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct	s_ints
{
	int			i;
	int			j;
	int			l;
	int			m;
	int			len;
}				t_ints;

typedef struct	s_vars
{
	int			args_len;
	int			env_len;
	int			e;
	int			len;
	char		*line;
	char		*path;
	char		*home;
	char		*pwd;
	char		*temp;
	char		*newlvl;
	char		*both;
	char		*var;
	char		*val;
	char		**e_args;
	char		**temp1;
	char		**temp2;
	char		**args;
	char		**paths;
	char		cwd[512];
	char		**env;
}				t_vars;

void			ft_init_vars(t_vars *t_v);
void			ft_check_args(t_vars *t_v, int i, const char **in);
void			ft_extern(t_vars *t_v);
void			ft_shsplit(t_vars *t_v, int i, int j, int k);
int				ft_argcount(char *str, int i, int counter);
int				ft_chrpos(char *str, char c);
void			ft_builtin(t_vars *t_v, int i);
void			ft_echo(t_vars *t_v);
void			ft_cd(t_vars *t_v);
char			*ft_envseek(t_vars *t_v, char *arg);
void			ft_unsetenv(t_vars *t_v);
void			ft_export(t_vars *t_v);
void			ft_setenv(t_vars *t_v, int j, int m, int l);
void			ft_env(t_vars *t_v);
void			ft_check_line(t_vars *t_v);
void			ft_errexit(t_vars *t_v);
void			ft_shlvl(t_vars *t_v);

#endif
