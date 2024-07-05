/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:38 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/09/13 18:41:23 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>  

char	**ft_split(char const *s, char c);
char	*ft_word(char const *str, int start, int end);
char	**ft_free(char **str, int x);
int		ft_open(char *s, int i);
int		ft_countwords(char const *s, char c);
int		ft_wordend(char const *s, char c, int i);
void	exe(char *cmd, char **env);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s, const char *b, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	exe2(char *path, char **cmds, char **env, char **paths);
size_t	ft_tablen(char **str);

#endif