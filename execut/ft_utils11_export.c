/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils11_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/22 20:32:27 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	search_key1(t_var *tmp, char *key_val)
{
	char	*save;
	char	*save1;
	char	*key;
	char	*value;

	key = ft_substr(key_val, 0, ft_strlen(key_val) - \
	ft_strlen(ft_strchr(key_val, '=')) - 1);
	value = ft_substr(key_val, ft_strlen(key_val) - \
	ft_strlen(ft_strchr(key_val, '=')) + 1, ft_strlen(key_val));
	if (tmp->content)
		free(tmp->content);
	if (tmp->value)
		free(tmp->value);
	tmp->value = ft_substr(value, 0, ft_strlen(value));
	save = ft_strjoin(key, "=");
	save1 = ft_strjoin(save, value);
	tmp->content = ft_substr(save1, 0, ft_strlen(save1));
	free(save1);
	free(save);
	free(value);
	free(key);
}

static void	search_key2(t_var *tmp, char *key_val)
{
	char	*save;
	char	*save1;
	char	*key;
	char	*value;

	key = ft_substr(key_val, 0, ft_strlen(key_val) - \
	ft_strlen(ft_strchr(key_val, '=')) - 1);
	value = ft_substr(key_val, ft_strlen(key_val) - \
	ft_strlen(ft_strchr(key_val, '=')) + 1, ft_strlen(key_val));
	save = ft_strjoin(tmp->value, value);
	if (tmp->value)
		free(tmp->value);
	tmp->value = ft_substr(save, 0, ft_strlen(save));
	free(save);
	save = ft_substr(tmp->content, 0, ft_strlen(tmp->content));
	if (tmp->content)
		free(tmp->content);
	save1 = ft_strjoin(save, value);
	tmp->content = ft_substr(save1, 0, ft_strlen(save1));
	free(save1);
	free(save);
	free(value);
	free(key);
}

void	search_key(t_var **list, char *key_val)
{
	t_var	*tmp;
	char	*key;

	tmp = *list;
	key = ft_substr(key_val, 0, ft_strlen(key_val) - \
	ft_strlen(ft_strchr(key_val, '=')) - 1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (!ft_strchr(tmp->content, '='))
				search_key1(tmp, key_val);
			else
				search_key2(tmp, key_val);
			break ;
		}
		tmp = tmp->next;
	}
	free(key);
}
