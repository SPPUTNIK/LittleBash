/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:13:32 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 18:30:32 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	struct_init(t_list *p)
{
	p->line2 = readline("➜  minishell ");
	if (p->line2 && p->line2[0] != 0)
		add_history(p->line2);
	p->error = 0;
	p->errorx = 0;
	p->ext = 0;
	if (p->line2 == NULL)
		p->ext = 1;
	if (p->line2 == NULL || check_piipe(p))
		return (0);
	p->line = pr_strdup("");
	p = dollar_init(p);
	free(p->line2);
	p = qts_check(p);
	if (p->ext != 1 && p->errorx != 1 && p->error != 1)
	{
		p->wn = pr_wnb2(p->line, ' ') + 1;
		p->m = malloc(sizeof(t_mini));
		p = struct_beta(p);
	}
	return (0);
}

t_list	*struct_beta(t_list *p)
{
	p->m->ii = 0;
	p->m->oo = 0;
	p->m->hr = 0;
	p->m->op = 0;
	p->m->open = malloc(sizeof(char *) * p->wn);
	p->m->ouf = malloc(sizeof(char *) * p->wn);
	p->m->inf = malloc(sizeof(char *) * p->wn);
	p->m->her = malloc(sizeof(char *) * p->wn);
	p->m->val = malloc(sizeof(char *) * p->wn);
	p->m->otype = malloc(sizeof(int) * p->wn);
	p->m->j = 0;
	p->m->next = NULL;
	p->i = 0;
	p->on = 0;
	return (p);
}

t_mini	*new_node(t_list *p)
{
	t_mini	*m;

	m = malloc(sizeof(t_mini));
	m->ouf = malloc(sizeof(char *) * p->wn);
	m->open = malloc(sizeof(char *) * p->wn);
	m->inf = malloc(sizeof(char *) * p->wn);
	m->her = malloc(sizeof(char *) * p->wn);
	m->val = malloc(sizeof(char *) * p->wn);
	m->otype = malloc(sizeof(int) * p->wn);
	m->ii = 0;
	m->hr = 0;
	m->oo = 0;
	m->op = 0;
	m->j = 0;
	p->m->j = 0;
	m->next = NULL;
	return (m);
}

t_mini	*goto_last(t_mini *m)
{
	if (!m)
		return (0);
	while (m->next != NULL)
		m = m->next;
	return (m);
}

t_mini	*addlast_node(t_mini **m, t_mini *new)
{
	if (*m == NULL)
		*m = new;
	else
	{
		*m = goto_last(*m);
		(*m)->next = new;
	}
	return (*m);
}
