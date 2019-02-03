/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:04:04 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/03 20:52:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int
	free_heap(int exit, char **paths, char **args)
{
	if (paths)
		ft_tabdel((void ***)&paths);
	if (args)
		ft_tabdel((void ***)&args);
	return (exit);
}

static int
	execute_cmd_core(char **env, char **args, char **paths)
{
	int		i;
	char	*err;

	i = 0;
	err = " : command not found";
	while (paths[i])
	{
		if (access(paths[i], F_OK) == 0)
		{
			if (access(paths[i], X_OK) == 0)
				execve(paths[i], args, env);
			else
				err = " : Permission denied";
			break ;
		}
		++i;
	}
	ft_putstr_fd(*args, 2);
	put_error(err);
	ft_tabdel((void ***)&args);
	ft_tabdel((void ***)&paths);
	return (127);
}

int
	execute_cmd(char *cmd, char **env)
{
	char	**args;
	char	**paths;
	int		status;
	int		childpid;

	if (!(args = ft_split_chars(cmd, ft_isspace_wnt)))
		return (2);
	if (!(paths = get_paths(env, args[0])))
	{
		ft_putstr_fd(*args, 2);
		put_error(" : command not found");
		return (free_heap(127, paths, args));
	}
	if ((childpid = fork()) == -1)
		return (free_heap(1, paths, args));
	if (childpid == 0)
		return (execute_cmd_core(env, args, paths));
	waitpid(childpid, &status, 0);
	free_heap(1, paths, args);
	if (WIFSIGNALED(status))
		return (128 + status);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}
