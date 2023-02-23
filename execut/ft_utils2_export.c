/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:13 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/23 18:22:39 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	key_value_only_equal(t_var **t_env, t_var **t_exp, char *key_val)
{
	char	*key;
	int		len;
	char	*value;

	len = ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, ft_strlen(key_val) - len);
	value = ft_substr(key_val, ft_strlen(key_val) - len + 1, \
	ft_strlen(key_val));
	if (!is_existed(t_env, key))
		ft_lstadd_back(t_env, ft_lstnew(key_val));
	else if (is_existed(t_env, key) == 1)
		*t_env = ft_lstnew(key_val);
	else
		write_again(t_env, key, value);
	if (!is_existed(t_exp, key))
		ft_lstadd_back(t_exp, ft_lstnew(key_val));
	else if (is_existed(t_exp, key) == 1)
		*t_exp = ft_lstnew(key_val);
	else
		write_again(t_exp, key, value);
	free(key);
	free(value);
}

static void	key_value_plus_equal_in2(t_var **list, char *key_val)
{
	int		len;
	char	*key;
	char	*value;
	char	*save;
	char	*save1;

	len = ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, ft_strlen(key_val) - len - 1);
	value = ft_substr(key_val, ft_strlen(key_val) - len + 1, \
	ft_strlen(key_val));
	save = ft_strjoin(key, "=");
	save1 = ft_strjoin(save, value);
	*list = ft_lstnew(save1);
	free(save);
	free(save1);
	free(key);
	free(value);
}

static void	key_value_plus_equal_in1(t_var **list, char *key_val)
{
	int		len;
	char	*key;
	char	*value;
	char	*save;
	char	*save1;

	len = ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, ft_strlen(key_val) - len - 1);
	value = ft_substr(key_val, ft_strlen(key_val) - len + 1, \
	ft_strlen(key_val));
	save = ft_strjoin(key, "=");
	save1 = ft_strjoin(save, value);
	ft_lstadd_back(list, ft_lstnew(save1));
	free(save);
	free(save1);
	free(key);
	free(value);
}

void	key_value_plus_equal_in(t_var **list, char *key_val)
{
	int		len;
	char	*key;

	len = ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, ft_strlen(key_val) - len - 1);
	if (!is_existed(list, key))
		key_value_plus_equal_in1(list, key_val);
	else if (is_existed(list, key) == 1)
		key_value_plus_equal_in2(list, key_val);
	else
		search_key(list, key_val);
	free(key);
}

int	key_value_plus_equal(t_var **t_env, t_var **t_exp, char *key_val, int len)
{
	char	*key;

	key = ft_substr(key_val, 0, ft_strlen(key_val) - len - 1);
	if (check_name_key(key))
		return (-1);
	key_value_plus_equal_in(t_exp, key_val);
	key_value_plus_equal_in(t_env, key_val);
	free(key);
	return (0);
}
