
#include <minishell.h>

void	ft_builtin(t_vars *t_v, int i)
{
	t_v->e = -1;
	if (i == 0)
		ft_echo(t_v); // in[0] echo : use ft_echo
	else if (i == 1)
		ft_export(t_v); // in[1] set environment : ft_export
	else if (i == 2)
		ft_unsetenv(t_v); // in[2] unset : ft_unsetenv
	else if (i == 3)
	{
		ft_cd(t_v); // in[3] cd : ft_cd
		ft_bzero((void *)t_v->cwd, sizeof(t_v->cwd)); // clear cur working dir to put new one
		getcwd(t_v->cwd, sizeof(t_v->cwd)); // use getcwd to get cur working dir
		t_v->var = "PWD";
		t_v->val = t_v->cwd; // save cwd in val for use later and if we make changes
		ft_setenv(t_v, -1, 0, -1);
	}
	else if (i == 4) 
		ft_env(t_v); // in[4] env : ft_env
	else if (i == 5)
		t_v->e = 9; // in[5] exit : set status to 9
}

void	ft_echo(t_vars *t_v)
{
	t_ints		k;
	char		*temp;

	k.i = 0;
	k.j = -1;
	if (t_v->args_len > 1)
	{
		while (++k.i < t_v->args_len)
		{
			if (t_v->args[k.i][0] == '$')
				temp = ft_envseek(t_v, t_v->args[k.i]);
			else
				temp = t_v->args[k.i];
			ft_putstr(temp);
			if (k.i != t_v->args_len)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}

void	ft_cd(t_vars *t_v)
{
	if (t_v->args_len == 1)
		t_v->path = ft_strdup(t_v->home);
	else if (t_v->args_len > 1)
	{
		if (t_v->args[1][0] == '~')
		{
			t_v->newlvl = t_v->args[1];
			t_v->path = ft_strjoin(t_v->home, ++t_v->newlvl);
			t_v->newlvl--;
		}
		else if (ft_strcmp(t_v->args[1], "-") == 0)
			t_v->path = ft_strdup(ft_envseek(t_v, "OLDPWD"));
		else
			t_v->path = ft_strdup(t_v->args[1]);
	}
	t_v->len = chdir(t_v->path);
	if (t_v->len == 0)
	{
		t_v->var = "OLDPWD";
		t_v->val = t_v->cwd;
		ft_setenv(t_v, -1, 0, -1);
	}
	else
		ft_putendl("Error: chdir Failed");
}
