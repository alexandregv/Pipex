/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:46:07 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/03 20:59:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int
	put_error(char *error)
{
	ft_putendl_fd(error, 2);
	return (1);
}

static char
	**freepath(char **path)
{
	if (path)
		ft_tabdel((void ***)&path);
	return (NULL);
}

static char
	**check_path(char **path, char *file)
{
	if (!path && (!(path = ft_strtabnew(1))
		|| !(path[0] = ft_strdup(file))))
		return (freepath(path));
	return (path);
}

char
	**get_paths(char **env, char *file)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	if ((!(path = NULL) && file[0] != '/') && !(ft_strnequ(file, "./", 2)))
	{
		while (env[i] && !ft_strnequ(env[i], "PATH=", 5))
			++i;
		if (!env[i] || !(path = ft_strsplit(env[i], ':')))
			return (NULL);
		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
		i = -1;
		while (path[++i])
		{
			tmp = path[i];
			path[i] = ft_strjoin3(path[i], "/", file);
			ft_strdel(&tmp);
			if (!path[i])
				return (freepath(path));
		}
	}
	return (check_path(path, file));
}
