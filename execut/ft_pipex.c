/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:40:36 by abel-bou        #+#    #+#             */
/*   Updated: 2022/07/19 14:51:24 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_connect_proccess(t_pipe *pi)
{
	int	i;

	i = 0;
	while (i < pi->size - 1)
	{
		if (pipe(&pi->pip_fd[i * 2]) < 0)
		{
			ft_err("minishell: ", "Pipe: ", "Not Connect All Pipes\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_one_node(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp)
{
	if (b->m->val[0])
	{
		if (b->m->inf[0] || b->m->ouf[0] || b->m->her[0])
			if (ft_redirection(t_env, pi, b))
				return ;
		if (!check_builtins(b->m->val[0]))
			no_need_proccess(pi, b, t_env, t_exp);
		else
			need_new_proccess(t_env, pi, b);
	}
	else
	{
		if (b->m->inf[0] || b->m->ouf[0] || b->m->her[0])
			ft_redirection(t_env, pi, b);
	}
}

void	ft_first_and_last_nodes(t_pipe *pi, t_list *b)
{
	if (pi->i == 0)
	{
		dup2(pi->fd[0], 0);
		if (b->m->ouf[0])
			dup2(pi->fd[1], 1);
		else
			dup2(pi->pip_fd[pi->i + 1], STDOUT_FILENO);
		ft_close(pi);
	}
	else if (pi->i == pi->size - 1)
	{
		if (b->m->inf[0] || b->m->her[0])
			dup2(pi->fd[0], 0);
		else
			dup2(pi->pip_fd[pi->i * 2 - 2], STDIN_FILENO);
		if (b->m->ouf[0])
			dup2(pi->fd[1], 1);
		ft_close(pi);
	}
}

void	ft_middle_nodes(t_pipe *pi, t_list *b)
{
	if (b->m->inf[0] || b->m->her[0])
		dup2(pi->fd[0], 0);
	else
		dup2(pi->pip_fd[pi->i * 2 - 2], 0);
	if (b->m->ouf[0])
		dup2(pi->fd[1], 1);
	else
		dup2(pi->pip_fd[pi->i * 2 + 1], 1);
	ft_close(pi);
}
