/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeiat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:49:02 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/24 19:33:00 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_free(t_mini *m)
{
	free(m->her);
	free(m->inf);
	free(m->ouf);
	free(m->val);
	free(m->otype);
	free(m->open);
}

void	free_the_m(t_mini *m)
{
	int		i;
	t_mini	*tmp;

	while (m)
	{
		i = 0;
		while (m->her[i])
			free(m->her[i++]);
		i = 0;
		while (m->ouf[i])
			free(m->ouf[i++]);
		i = 0;
		while (m->val[i])
			free(m->val[i++]);
		i = 0;
		while (m->inf[i])
			free(m->inf[i++]);
		free_free(m);
		tmp = m->next;
		free(m);
		m = tmp;
	}
}

void	free_the_pi(t_pipe *p)
{
	int	i;

	i = 0;
	while (p->envr[i])
		free(p->envr[i++]);
	free(p->envr);
	free(p->pid_proc);
	free(p->pip_fd);
}

t_pipe	*pi_init(t_pipe *pi, t_list *b)
{
	pi->size = ft_lstsize(b->m);
	pi->pid_proc = malloc(sizeof(int) * pi->size);
	pi->pip_fd = malloc(sizeof(int) * (pi->size - 1) * 2);
	return (pi);
}
