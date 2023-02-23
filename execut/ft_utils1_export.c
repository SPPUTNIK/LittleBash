/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:13 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/23 16:28:17 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_existed(t_var **list, char *key)
{
	t_var	*tmp;

	tmp = *list;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_name_key(char *key)
{
	int	i;

	i = 1;
	if (key[0] != '_' && ft_isalpha(key[0]) == 0)
	{
		ft_err("minishell: export:", key, ": not a valid identifier\n", 1);
		return (-1);
	}
	while (key[i] && key[i] != '=')
	{
		if ((key[i] == '+' && key[i + 1] != '=')
			|| (key[i] != '_' && ft_isalphanum(key[i]) == 0
				&& key[i] != '+'))
		{
			ft_err("minishell: export:", key, ": not a valid identifier\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	write_again(t_var **list, char *key, char *value)
{
	t_var	*tmp;
	char	*tmpp;
	char	*tmpp2;

	tmp = *list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmpp = ft_strjoin(key, "=");
			tmpp2 = ft_strjoin(tmpp, value);
			free(tmpp);
			if (tmp->content)
				free(tmp->content);
			tmp->content = ft_substr(tmpp2, 0, ft_strlen(tmpp2));
			free(tmp->value);
			tmp->value = ft_substr(value, 0, ft_strlen(value));
			free(tmpp2);
			return ;
		}
		tmp = tmp->next;
	}
}

void	sort_env(t_var **t_exp)
{
	char	*swap;
	t_var	*tmp;
	t_var	*tmp1;

	tmp = *t_exp;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (ft_strcmp(tmp->content, tmp1->content) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp1->content;
				tmp1->content = swap;
			}
			tmp1 = tmp1->next;
		}
		print_exp(tmp);
		tmp = tmp->next;
	}
}
