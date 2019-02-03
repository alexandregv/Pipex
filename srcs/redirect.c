/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:46:26 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/03 21:17:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int
	put_redir_error(char *file, char *err)
{
	ft_putstr_fd(file, 2);
	ft_putendl_fd(err, 2);
	return (1);
}

int
	redirect(char *cmd, char *file, char **env, char in)
{
	int		ret;
	int		fd_g;
	int		fd_d;
	int		stdin;

	fd_d = in ? open(file, O_RDONLY)
			: open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_d >= 0)
	{
		fd_g = (in ? 0 : 1);
		stdin = dup(fd_g);
		dup2(fd_d, fd_g);
		ret = execute_cmd(cmd, env);
		write(fd_g, "\0", 0);
		dup2(stdin, fd_g);
		close(fd_d);
		close(stdin);
		return (ret);
	}
	else if (access(file, F_OK) == 0)
		return (put_redir_error(file, ": Permission denied"));
	else
		return (put_redir_error(file, ": No such file or directory"));
}
