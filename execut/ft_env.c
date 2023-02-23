/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:17 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/24 00:01:56 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cpy_env(t_var **t_env, t_var **t_exp, char **env)
{
	int	i;

	*t_env = ft_lstnew(env[0]);
	*t_exp = ft_lstnew(env[0]);
	i = 1;
	while (env[i])
	{
		ft_lstadd_back(t_env, ft_lstnew(env[i]));
		ft_lstadd_back(t_exp, ft_lstnew(env[i]));
		i++;
	}
}

void	ft_env(t_var **t_env)
{
	t_var	*tmp;

	tmp = *t_env;
	if (!tmp)
	{
		ft_err("minishell : ", "env ", ": No such file or directory\n", 127);
		return ;
	}
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
