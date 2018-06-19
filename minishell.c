
#include <minishell.h>

void			ft_extern(t_vars *t_v)
{
	int			sig;
	int			pid;

	sig = 1;
	if (t_v->path == NULL && t_v->e == 0)  // check for path if not found
	{
		ft_putstr("Error: Command Not Found: ");
		ft_putendl(t_v->args[0]);
	}
	else if (t_v->path != NULL && t_v->e == 0) // if found
	{
		pid = fork(); // we use for to duplicate the process
		if (pid < 0)
			ft_putendl("Error: Forking Failed"); // if fork failed
		else if (pid > 0)
			wait(&sig); // wait() parents to wait for child process
		else if (pid == 0)
			execve(t_v->path, t_v->e_args, t_v->env); // the execute the command given
	}
	else if (t_v->e == -1)
		t_v->e = 0;
}

void			ft_check_args(t_vars *t_v, int i, const char **in)
{
	while (++i < 6 && t_v->e == 0) // go through each arg and make sure you find it in in[]
	{
		if (t_v->e == 0 && ft_strcmp(t_v->args[0], in[i]) == 0)
			ft_builtin(t_v, i); // ecxecuse the user command is dedicated functions
	}
	i = -1;
	if (t_v->e == 0 && access(t_v->args[0], F_OK) == -1) // checking for access rightds to a file
	{
		while (t_v->e == 0 && ++i < ft_arrlen(t_v->paths))// if permision not granted put slash check next file
		{
			t_v->temp = ft_strjoin(t_v->paths[i], "/");
			t_v->path = ft_strjoin(t_v->temp, t_v->args[0]);
			ft_strdel(&t_v->temp);
			if (access(t_v->path, F_OK) != -1)
				break ; // if access granted get out of loop
			else
				ft_strdel(&t_v->path);
		}
	}
	else if (t_v->e == 0) //check for no errors
		t_v->path = ft_strdup(t_v->args[0]);
	t_v->e_args = t_v->args;
	ft_extern(t_v); // otherwise go ahead and run the command
}

void			ft_init_vars(t_vars *t_v)
{
	char		*temp;

	if (t_v->line != NULL)
		ft_strdel(&t_v->line);
	if (t_v->args != NULL)
		ft_arrdel(t_v->args);
	if (t_v->path != NULL)
		ft_strdel(&t_v->path);
	if (t_v->paths != NULL && *t_v->paths != NULL)
		ft_arrdel(t_v->paths);
	t_v->home = ft_envseek(t_v, "HOME");
	t_v->pwd = ft_envseek(t_v, "PWD");
	temp = ft_envseek(t_v, "PATH");
	if (temp)
		t_v->paths = ft_strsplit(temp, ':'); // get path portion of env_var
	else
		t_v->paths = NULL;
	if (getcwd(t_v->cwd, sizeof(t_v->cwd)) == NULL) // if unable to get working dir set e var to 1
		t_v->e = 1;
	t_v->args_len = 0;
	t_v->line = NULL;
}

int				main(void)
{
	//declare eviron variable 
	extern char	**environ;
	t_vars		t_v; // own object to store vars

	t_v.e = -1;			//initialise own varibles
	t_v.line = NULL;
	t_v.args = NULL;
	t_v.path = NULL;
	t_v.paths = NULL;
	t_v.env_len = ft_arrlen(environ); // get len  of environ variable
	t_v.env = (char **)ft_memalloc(sizeof(char *) * (t_v.env_len + 1)); // create char* list for env var
	while (++t_v.e < t_v.env_len)
		t_v.env[t_v.e] = ft_strdup(environ[t_v.e]); // populate list with variable
	t_v.env[t_v.e] = NULL; // set end of list to null
	t_v.e = 0; // e = 0 incdicates no errors
	ft_shlvl(&t_v); // function to find cur shell lvl add 1 and replace lvl var in env var
	while (1)
	{
		ft_init_vars(&t_v); // initialize remaining var in t_v
		if (t_v.e != 0) // if thres an error exit and clear out t_v obj
			ft_errexit(&t_v);
		ft_putstr("$>"); // display on screen
		get_next_line(STDIN, &t_v.line); //take stdin and put it in t_v line
		ft_check_line(&t_v);
	}
	return (0);
}
