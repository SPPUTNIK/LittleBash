/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:35:35 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/23 16:28:46 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_plus(char *con)
{
	int	i;

	i = 0;
	while (con[i])
	{
		if (con[i] == '+' && con[i + 1] == '=')
			return (1);
		else if (con[i] == '=')
			return (0);
		i++;
	}
	return (0);
}

t_var	*ft_lstnew(char *content)
{
	t_var	*node;
	int		len;

	node = NULL;
	node = malloc(sizeof(t_var));
	if (!node)
		return (0);
	node->content = ft_strdup(content);
	if (node->content && ft_strchr(node->content, '='))
	{
		len = ft_strlen(ft_strchr(node->content, '='));
		node->key = ft_substr(node->content, 0, ft_strlen(node->content) \
		- len - check_plus(node->content));
		node->value = ft_substr(node->content, ft_strlen(node->content) \
		- len + 1, ft_strlen(node->content));
	}
	else
	{
		node->key = ft_strdup(content);
		node->value = ft_strdup("");
	}
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_var **lst, t_var *new)
{
	t_var	*tmp;

	if (!lst)
		lst = &new;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_lstsize(t_mini *m)
{
	t_mini	*tmp;
	int		i;

	tmp = m;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
