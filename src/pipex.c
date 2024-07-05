/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:34 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/11/26 00:18:21 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child(char **argv, int *pfd, char **env, int fd)
{
	dup2(pfd[1], 1);
	dup2(fd, 0);
	close(pfd[0]);
	close(fd);
	exe(argv[2], env);
}

void	parent(char **argv, int *pfd, char **env, int fd)
{
	dup2(pfd[0], 0);
	dup2(fd, 1);
	close(pfd[1]);
	close(fd);
	exe(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	id;
	int	pfd[2];
	int	x;
	int	fd1;
	int	fd2;

	if (argc < 5)
	{
		write(2, "too few arguments!\n", 20);
		exit(1);
	}
	if (argc > 5)
		return (write(2, "too many arguments!\n", 21), 0);
	fd1 = ft_open(argv[1], 0);
	fd2 = ft_open(argv[4], 1);
	x = pipe(pfd);
	if (x == -1)
		exit(EXIT_FAILURE);
	id = fork();
	if (id == -1)
		exit(EXIT_FAILURE);
	if (!id)
		child(argv, pfd, env, fd1);
	parent(argv, pfd, env, fd2);
}
