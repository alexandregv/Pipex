/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:50:35 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/03 19:59:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int
	exec_next_cmd(t_pipex *pipex, int fildes[2])
{
	int		ret;

	dup2(fildes[0], 0);
	close(fildes[0]);
	close(fildes[1]);
	if (pipex->idcmd == pipex->nbcmd - 1)
		ret = redirect(*pipex->cmds, pipex->outfile, pipex->env, 0);
	else
	{
		ret = exec_pipes(pipex);
	}
	return (ret);
}

static int
	exec_cmd(t_pipex *pipex, int fildes[2])
{
	int		ret;

	dup2(fildes[1], 1);
	close(fildes[0]);
	close(fildes[1]);
	if (pipex->idcmd == 0)
		ret = redirect(*pipex->cmds, pipex->infile, pipex->env, 1);
	else
		ret = execute_cmd(*pipex->cmds, pipex->env);
	return (ret);
}

static int
	exec_one_pipe(t_pipex *pipex, int fildes[2])
{
	int		pid[2];
	int		stat[2];

	if ((pid[0] = fork()) == -1)
		return (put_error("fork error"));
	else if (!pid[0])
	{
		++pipex->idcmd;
		++pipex->cmds;
		return (exec_next_cmd(pipex, fildes));
	}
	if ((pid[1] = fork()) == -1)
		return (put_error("fork error"));
	else if (!pid[1])
		return (exec_cmd(pipex, fildes));
	close(fildes[0]);
	close(fildes[1]);
	waitpid(pid[0], &stat[0], 0);
	waitpid(pid[1], &stat[1], 0);
	if ((WIFEXITED(stat[0])))
		return (WEXITSTATUS(stat[0]));
	return (WIFEXITED(stat[1]) ? WEXITSTATUS(stat[1]) : 1);
}

int
	exec_pipes(t_pipex *pipex)
{
	int		fildes[2];

	if (pipe(fildes) == -1)
		return (put_error("pipe error"));
	return (exec_one_pipe(pipex, fildes));
}

int
	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (put_error("Usage : ./pipex file1 cmd1 cmd2 [cmd..] file2"));
	pipex.infile = av[1];
	pipex.outfile = av[ac - 1];
	pipex.nbcmd = ac - 3;
	pipex.idcmd = 0;
	pipex.cmds = &av[2];
	pipex.env = env;
	return (exec_pipes(&pipex));
}
