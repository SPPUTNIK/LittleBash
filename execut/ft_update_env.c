/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:45:45 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/25 17:19:26 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_pwd(t_var **var)
{
	t_var	*tmp;
	char	*pwd;

	tmp = *var;
	pwd = ft_strdup(ft_pwd());
	if (!pwd)
		return ;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
		{
			free(tmp->content);
			tmp->value = ft_substr(pwd, 0, ft_strlen(ft_pwd()));
			tmp->content = ft_strjoin("PWD=", tmp->value);
			free(pwd);
			return ;
		}
		tmp = tmp->next;
	}
	free(pwd);
}

char	*ft_current_pwd(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

void	ft_update_old_pwd(t_var **var)
{
	char	*old_pwd;
	t_var	*tmp;

	tmp = *var;
	old_pwd = ft_current_pwd(var);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "OLDPWD"))
		{
			if (tmp->value)
				free(tmp->value);
			free(tmp->content);
			tmp->content = ft_strjoin("OLDPWD=", old_pwd);
			tmp->value = ft_strdup(old_pwd);
			free(old_pwd);
			return ;
		}
		tmp = tmp->next;
	}
	free(old_pwd);
}

void	update_pwd_env_exp(t_var **t_env, t_var **t_exp)
{
	ft_update_old_pwd(t_env);
	ft_update_old_pwd(t_exp);
	ft_update_pwd(t_env);
	ft_update_pwd(t_exp);
}
