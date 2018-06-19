
#include <minishell.h>

int				ft_argcount(char *str, int i, int counter)
{
	while (i < (int)ft_strlen(str) && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '"')
			i++;
		else
		{
			counter++;
			if (i > 0 && str[i - 1] == '"' && i != (int)ft_strlen(str))
			{
				while (str[i] && str[i] != '"')
					i++;
			}
			else
			{
				while (str[i] && str[i] != ' ' && str[i] != '\t')
					i++;
			}
		}
	}
	return (counter);
}

void			ft_shsplit(t_vars *t_v, int i, int j, int k)
{
	t_v->args_len = ft_argcount(t_v->line, 0, 0); // count arguments in the line
	t_v->args = (char**)ft_memalloc(sizeof(char *) * (t_v->args_len + 1)); //make like for arguments
	if (!t_v->args) // if can't make list set e var to 2(for error checking)
		t_v->e = 2;
	while (t_v->e == 0 && ++j < t_v->args_len && t_v->line[i])
	{
		k = 0;
		while ((t_v->line[i] == ' ' || t_v->line[i] == '\t'
			|| t_v->line[i] == '"') && t_v->line[i])
			i++; // skip all charcter not prutinent to the command
		if (i > 0 && t_v->line[i - 1] == '"')
		{
			while (t_v->line[i + k] != '"' && t_v->line[i + k])
				k++;
		}
		else
		{
			while ((t_v->line[i + k] != ' ' && t_v->line[i + k] != '\t')
				&& t_v->line[i + k])
				k++;
		}
		t_v->args[j] = ft_strsub(t_v->line, i, k); // get final arguments by taking only the comand
		i += k;
	}
	t_v->args[j] = NULL; // set last node int list to null
}

void			ft_check_line(t_vars *t_v)
{
	const char	*in[6];
	// initialize [] with riquired commands
	in[0] = "echo";
	in[1] = "setenv";
	in[2] = "unsetenv";
	in[3] = "cd";
	in[4] = "env";
	in[5] = "exit";
	if (t_v->line != NULL)  // if lone not empty
	{
		ft_shsplit(t_v, 0, -1, 0); // take input and place command in t_v->args list
		if (t_v->args[0] != NULL) // check if args are valid if any
			ft_check_args(t_v, -1, in);
	}
	else
		t_v->args = NULL;
}

void			ft_shlvl(t_vars *t_v)
{
	int		lvl;

	lvl = ft_atoi(ft_envseek(t_v, "SHLVL")) + 1; // find string "SHLVL"'s value and add 1 to it
	t_v->newlvl = ft_itoa(lvl); // set new lvl
	t_v->var = "SHLVL";
	t_v->val = t_v->newlvl;
	ft_setenv(t_v, -1, 0, -1); // set up new environment with new shlvl
	ft_strdel(&t_v->newlvl); // clear newlvl var
}

void			ft_errexit(t_vars *t_v)
{
	ft_arrdel(t_v->env);
	if (t_v->paths != NULL)
		ft_arrdel(t_v->paths);
	if (t_v->e == 1)
		ft_puterror("Error: cannot get current working directory");
	if (t_v->e == 2)
		ft_puterror("Error: cannot malloc");
	if (t_v->e == 9)
	{
		ft_putendl("Exiting");
		exit(EXIT_SUCCESS);
	}
}
