/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:00:17 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/03 19:29:00 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

typedef struct	s_pipex
{
	char	*infile;
	char	*outfile;
	int		nbcmd;
	int		idcmd;
	char	**cmds;
	char	**env;
}				t_pipex;

char			**get_paths(char **env, char *file);
int				redirect(char *cmd, char *file, char **env, char in);
int				put_error(char *error);
int				execute_cmd(char *cmd, char **env);
int				exec_pipes(t_pipex *pipex);

#endif
