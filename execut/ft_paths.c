/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:40:36 by abel-bou        #+#    #+#             */
/*   Updated: 2022/07/19 14:51:24 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmppp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (-1);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < (n - 1) && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

char	**find_path(t_var *env)
{
	int		i;
	t_var	*tmp;

	i = 0;
	tmp = env;
	while (tmp && ft_strncmppp(tmp->key, "PATH", 4))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (ft_split(tmp->value, ':'));
}

char	*get_pathss(t_var *env, char *cmd)
{
	int		i;
	char	**path;
	char	*cmdd;

	path = find_path(env);
	if (!path)
		return (cmd);
	i = 0;
	while (path[i])
	{
		cmdd = ft_strjoin("/", cmd);
		path[i] = ft_strjoin(path[i], cmdd);
		free(cmdd);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
	return (cmd);
}

void	ft_close(t_pipe *pi)
{
	int	j;

	j = 0;
	while (j < (pi->size - 1) * 2)
	{
		close(pi->pip_fd[j]);
		j++;
	}
}
