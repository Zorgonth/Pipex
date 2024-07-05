/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:57:20 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/13 14:25:07 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, len);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	i;
	size_t			src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (destsize == 0)
		return (src_len);
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dest_len > dstsize)
		return (dstsize + src_len);
	while (src[i] && dest_len + i < dstsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

size_t	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
