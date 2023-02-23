/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:20 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/25 02:29:14 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	msg_err(char *value)
{
	ft_err("minishell: unset: ", value, ": not a valid identifier\n", 1);
}

int	check_name(char *key)
{
	int	i;

	i = 1;
	if (key[0] != '_' && ft_isalpha(key[0]) == 0)
	{
		g_glo.exit = 1;
		return (-1);
	}
	while (key[i])
	{
		if (key[i] != '_' && ft_isalphanum(key[i]) == 0)
		{
			g_glo.exit = 1;
			return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_unset_in_list(t_var **list, char *key)
{
	t_var	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			delete_node_in_list(list, key);
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_unset(t_var **t_env, t_var **t_exp, t_list *b)
{
	int	i;

	i = 1;
	while (b->m->val[i])
	{
		if (check_name(b->m->val[i]))
			msg_err(b->m->val[i]);
		else
		{
			ft_unset_in_list(t_env, b->m->val[i]);
			ft_unset_in_list(t_exp, b->m->val[i]);
		}
		i++;
	}
}
