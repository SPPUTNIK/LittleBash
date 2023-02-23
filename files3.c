/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:32:04 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 01:12:53 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*south_herdo2(t_list *p)
{
	char	c;

	c = p->line[p->i];
	p->i++;
	while (p->line[p->i] != c && p->line[p->i])
		p->m->her[p->m->hr] = put_char(p->m->her[p->m->hr], p->line[p->i++]);
	if (p->line[p->i] == c)
		p->i++;
	p->m->hflag = 1;
	return (p);
}

t_list	*south_inpu2(t_list *p)
{
	char	c;

	c = p->line[p->i];
	p->i++;
	while (p->line[p->i] != c && p->line[p->i])
		p->m->inf[p->m->ii] = put_char(p->m->inf[p->m->ii], p->line[p->i++]);
	if (p->line[p->i] == c)
		p->i++;
	return (p);
}

t_list	*south_herdo(t_list *p)
{
	p->m->hflag = 0;
	p->i += 2;
	p->m->her[p->m->hr] = pr_strdup("");
	p->i = skip_space(p->line, p->i);
	while (check_ffile(p->line[p->i]) && p->line[p->i])
	{
		if (p->line[p->i] == '"' || p->line[p->i] == '\'')
			p = south_herdo2(p);
		else if (check_mfile(p->line[p->i]) && p->line[p->i])
			p->m->her[p->m->hr] = put_char(p->m->her[p->m->hr], \
			p->line[p->i++]);
		else
			break ;
	}
	if (p->m->her[p->m->hr][0] != 0)
	{
		p->m->hr++;
		p->m->itype = HERDO;
	}
	return (p);
}

t_list	*south_inpu(t_list *p)
{
	p->i++;
	p->m->inf[p->m->ii] = pr_strdup("");
	p->i = skip_space(p->line, p->i);
	while (check_ffile(p->line[p->i]) && p->line[p->i])
	{
		if (p->line[p->i] == '"' || p->line[p->i] == '\'')
			p = south_inpu2(p);
		else if (check_mfile(p->line[p->i]))
			p->m->inf[p->m->ii] = put_char(p->m->inf[p->m->ii], \
			p->line[p->i++]);
		else
			break ;
	}
	if (p->m->inf[p->m->ii][0] != 0)
	{
		p->m->ii++;
		p->m->itype = INPU;
		p->m->open[p->m->op] = INFF;
		p->m->op++;
	}
	return (p);
}
