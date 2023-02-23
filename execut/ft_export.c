/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:13 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/23 16:26:59 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_exp(t_var *var)
{
	t_var	*tmp;
	int		len;

	tmp = var;
	if (ft_strchr(tmp->content, '='))
	{
		free(tmp->key);
		len = ft_strlen(ft_strchr(tmp->content, '='));
		tmp->key = ft_substr(tmp->content, 0, \
		ft_strlen(tmp->content) - len);
		free(tmp->value);
		tmp->value = ft_substr(tmp->content, \
		ft_strlen(tmp->content) - len + 1, ft_strlen(tmp->content));
		printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
	}
	else
		printf("declare -x %s\n", tmp->content);
}

int	key_no_value(char *key, t_var **t_exp)
{
	if (check_name_key(key))
		return (-1);
	if (!is_existed(t_exp, key))
		ft_lstadd_back(t_exp, ft_lstnew(key));
	else if (is_existed(t_exp, key) == 1)
		*t_exp = ft_lstnew(key);
	return (0);
}

void	exec(t_var **t_env, t_var **t_exp, char *av)
{
	if (check_name_key(av))
		return ;
	else if (!ft_strchr(av, '='))
		key_no_value(av, t_exp);
	else
		key_value(t_env, t_exp, av);
	return ;
}

void	free_e(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		tmp = tmp->next;
	}
}

void	ft_export(t_var **t_env, t_var **t_exp, t_list *b)
{
	int	i;
	int	len;

	len = count_files(b->m->val);
	if (len > 1)
	{
		i = 1;
		while (b->m->val[i])
		{
			exec(t_env, t_exp, b->m->val[i]);
			i++;
		}
	}
	else
		sort_env(t_exp);
}
