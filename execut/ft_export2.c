/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:46:58 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/23 13:23:50 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	key_value2(char *key)
{
	free(key);
}

void	key_value(t_var **t_env, t_var **t_exp, char *key_val)
{
	int		i;
	int		len;
	char	*key;

	len = ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, ft_strlen(key_val) - len);
	i = 1;
	while (key_val[i])
	{
		if (key_val[i] == '=')
		{
			if (check_name_key(key))
				return (key_value2(key));
			key_value_only_equal(t_env, t_exp, key_val);
			return (key_value2(key));
		}
		else if (key_val[i] == '+' && key_val[i + 1] == '=')
		{
			key_value_plus_equal(t_env, t_exp, key_val, len);
			return (key_value2(key));
		}
		i++;
	}
}

int	count_files(char **files)
{
	int	i;

	i = 0;
	while (files[i])
		i++;
	return (i);
}
