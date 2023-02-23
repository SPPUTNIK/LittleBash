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

int	last_output_file(t_list *b, t_pipe *pi)
{
	if (b->m->otype[b->m->oo - 1] == OUTFILEE)
	{
		pi->fd[1] = open(b->m->ouf[b->m->oo - 1], O_CREAT | O_TRUNC \
		| O_WRONLY, 0644);
		if (pi->fd[1] < 0)
		{
			ft_err("minishell :", b->m->ouf[b->m->oo - 1], \
			" : Permission denied\n", 1);
			return (-1);
		}
	}
	else if (b->m->otype[b->m->oo - 1] == APPENDD)
	{
		pi->fd[1] = open(b->m->ouf[b->m->oo - 1], O_CREAT | O_APPEND \
		| O_WRONLY, 0644);
		if (pi->fd[1] < 0)
		{
			ft_err("minishell :", b->m->ouf[b->m->oo - 1], \
			" : Permission denied\n", 1);
			return (-1);
		}
	}
	return (0);
}

int	ft_redirect_out(t_pipe *pi, t_list *b)
{
	int	out_f;

	out_f = count_files(b->m->ouf);
	if (b->m->oo < out_f)
	{
		pi->fd[1] = open(b->m->ouf[b->m->oo], O_CREAT, 0644);
		if (pi->fd[1] < 0)
		{
			ft_err("minishell : ", b->m->ouf[b->m->oo], \
			" : Permission denied\n", 1);
			return (-1);
		}
		b->m->oo++;
		close(pi->fd[1]);
	}
	if (b->m->oo == out_f)
	{
		if (last_output_file(b, pi))
			return (-1);
	}
	return (0);
}

static int	ft_redirect2(t_list *b)
{
	ft_err("minishell : ", b->m->inf[b->m->ii], \
	" : No such file or directory\n", 127);
	return (-1);
}

int	ft_redirect_inp(t_pipe *pi, t_list *b)
{
	int	inf_f;

	inf_f = count_files(b->m->inf);
	if (b->m->inf[b->m->ii])
	{
		if (access(b->m->inf[b->m->ii], F_OK))
			return (ft_redirect2(b));
		else if (access(b->m->inf[b->m->ii], R_OK))
		{
			ft_err("minishell :", b->m->inf[b->m->ii], \
			" : Permission denied\n", 1);
			return (-1);
		}
	}
	if (b->m->ii == inf_f - 1 && b->m->itype == INPU)
	{
		pi->fd[0] = open(b->m->inf[b->m->ii], O_RDONLY, 0644);
		if (pi->fd[0] < 0)
			return (-1);
	}
	b->m->ii++;
	return (0);
}

int	ft_redirection(t_var **t_env, t_pipe *pi, t_list *b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	b->m->oo = 0;
	b->m->ii = 0;
	if (b->m->her[0])
		j = her_doc(b, pi, *t_env);
	while (b->m->open[i] && j != -1)
	{
		if (b->m->open[i] == OUFF)
			j = ft_redirect_out(pi, b);
		else if (b->m->open[i] == INFF)
			j = ft_redirect_inp(pi, b);
		i++;
	}
	return (j);
}
