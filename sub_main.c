/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 16:04:03 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*pipe_pipe(t_list *p)
{
	p->m->val[p->m->j] = NULL;
	p->m->inf[p->m->ii] = NULL;
	p->m->ouf[p->m->oo] = NULL;
	p->m->open[p->m->op] = ZERO;
	p->m->her[p->m->hr] = NULL;
	p->i++;
	p->i = skip_space(p->line, p->i);
	p->m = addlast_node(&p->m, new_node(p));
	p->m = p->m->next;
	p->m->next = NULL;
	return (p);
}

t_mini	*sf_salaw(t_mini *tmp, t_list *p)
{
	p->m->val[p->m->j] = NULL;
	p->m->inf[p->m->ii] = NULL;
	p->m->ouf[p->m->oo] = NULL;
	p->m->open[p->m->op] = ZERO;
	p->m->her[p->m->hr] = NULL;
	p->m->next = NULL;
	p->m = tmp;
	return (p->m);
}

t_list	*parser_v2(t_list *p)
{
	while (p->error != 1 && p->line[p->i])
	{
		p->i = skip_space(p->line, p->i);
		if (p->line[p->i] != '<' && p->line[p->i] != '>'
			&& p->line[p->i] != '|'
			&& p->error != 1)
			p = grep_command(p);
		if ((p->line[p->i] == '<' || p->line[p->i] == '>')
			&& p->error != 1)
			p = grep_files(p);
		if (p->line[p->i] == '|' && p->error != 1)
			p = pipe_pipe(p);
		if ((p->line[p->i] == '"' || p->line[p->i] == '\'')
			&& p->error != 1)
			p = qts_help(p);
	}
	return (p);
}

t_list	*parser(t_var *var, t_list *p)
{
	t_mini	*tmp;

	p->var = var;
	struct_init(p);
	tmp = p->m;
	if (p->ext != 1 && p->errorx != 1)
	{
		if (p->error != 1)
		{
			p->m->j = 0;
			p = parser_v2(p);
			p->m = sf_salaw(tmp, p);
		}
		free(p->line);
	}
	return (p);
}
