/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:21:48 by sal-zuba          #+#    #+#             */
/*   Updated: 2024/02/15 16:49:58 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	**get_path(char **env)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", ft_strlen(env[i])))
			tmp = ft_substr(env[i], 0, ft_strlen(env[i]));
		i++;
	}
	path = ft_split(tmp + 5, ':');
	free(tmp);
	tmp = NULL;
	return (path);
}

void	exe2(char *path, char **cmds, char **env, char **paths)
{
	if (!path)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, cmds[0], ft_strlen(cmds[0]));
		write(2, "\n", 1);
		ft_free(cmds, ft_tablen(cmds));
		ft_free(paths, ft_tablen(paths));
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmds, env) == -1)
	{
		ft_free(cmds, ft_tablen(cmds));
		ft_free(paths, ft_tablen(paths));
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	exe(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	**cmds;
	char	*exec;
	char	*tmp;

	i = 0;
	path = get_path(env);
	cmds = ft_split(cmd, ' ');
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		exec = ft_strjoin(tmp, cmds[0]);
		free(tmp);
		if (access(exec, X_OK | F_OK) == 0)
			break ;
		free(exec);
		exec = NULL;
		i++;
	}
	exe2(exec, cmds, env, path);
}
