/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:58:40 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 02:28:33 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_multi2(int i)
{
	ft_err("minishell: ", "fork: ", \
	"Resource temporarily unavailable\n", 1);
	return (i);
}

int	ft_multiple_node(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp)
{
	if (b->m->inf[0] || b->m->ouf[0] || b->m->her[0])
	{
		if (ft_redirection(t_env, pi, b))
			return (0);
	}
	pi->pid_proc[pi->i] = fork();
	if (pi->pid_proc[pi->i] == 0)
	{
		signal(SIGINT, handler);
		if (pi->i == 0 || pi->i == pi->size - 1)
			ft_first_and_last_nodes(pi, b);
		else
			ft_middle_nodes(pi, b);
		if (!check_builtins(b->m->val[0]))
			builtins(t_env, t_exp, b);
		else if (execve(get_pathss(*t_env, b->m->val[0]), b->m->val, \
		pi->envr) == -1)
			ft_is_directory(b->m->val[0]);
		exit(g_glo.exit);
	}
	else if (pi->pid_proc[pi->i] < 0)
		return (ft_multi2(-1));
	return (0);
}
