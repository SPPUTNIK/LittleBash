/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:58 by abdessamad        #+#    #+#             */
/*   Updated: 2022/08/24 21:53:28 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	go_to_path(t_list *b)
{
	if (chdir(b->m->val[1]))
	{
		ft_err("minishell : cd ", b->m->val[1], \
		": No such file or directory\n", 127);
		return (-1);
	}
	return (0);
}

void	msg_errs(char *value)
{
	ft_err("minishell: ", value, ": HOME not set\n", 1);
}

void	ft_cd(t_list *b, t_var **t_env, t_var **t_exp)
{
	t_var	*tmp;
	int		wn;
	char	cmd[1024];

	tmp = *t_env;
	wn = count_files(b->m->val);
	if (wn == 1)
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, "HOME"))
			{
				if (!chdir(tmp->value))
				{
					update_pwd_env_exp(t_env, t_exp);
					return ;
				}
			}
			tmp = tmp->next;
		}
		if (!tmp)
			msg_errs(b->m->val[0]);
	}
	else if (!go_to_path(b) && getcwd(cmd, sizeof(cmd)))
		update_pwd_env_exp(t_env, t_exp);
}
