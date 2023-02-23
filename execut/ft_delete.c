/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:13 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/23 16:26:29 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	le_free(t_var *tmp)
{
	free(tmp->content);
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}

void	delete_node_in_list(t_var **list, char *key)
{
	t_var	*tmp;
	t_var	*prev;

	tmp = *list;
	if (tmp && !(ft_strcmp(tmp->key, key)))
	{
		*list = (*list)->next;
		le_free(tmp);
		return ;
	}
	else
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, key))
			{
				prev->next = tmp->next;
				le_free(tmp);
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
