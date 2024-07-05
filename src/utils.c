/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:15:10 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/10/27 12:38:00 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open(char *s, int i)
{
	int	fd;

	if (i == 0)
	{
		if (access(s, F_OK) == 0 && access(s, R_OK) == 0)
		{
			fd = open(s, O_RDONLY);
			if (fd < 0)
				exit(127);
		}
		else
		{
			write(2, "zsh: no such file or directory: ", 32);
			write(2, s, ft_strlen(s));
			write(2, "\n", 1);
			exit(0);
		}
	}
	if (i == 1)
		fd = open(s, O_APPEND | O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		exit(127);
	return (fd);
}

char	*ft_strnstr(const char *s, const char *b, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(b);
	if (i == 0)
		return ((char *)s);
	while (j < len && s[j])
	{
		if (j + i <= len && !ft_strncmp(s + j, b, i))
			return ((char *)s + j);
		else
			j++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (n == 0)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (a[i] && b[i] && a[i] == b[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = ft_strlen(s + start);
	if (i > len)
		i = len;
	a = (char *)malloc(i + 1);
	if (!a)
		return (NULL);
	j = 0;
	while (j < i)
	{
		a[j] = s[start + j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
