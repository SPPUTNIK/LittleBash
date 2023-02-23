/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:02:19 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/19 14:33:04 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*l_quotes(t_list *p)
{
	char	c;

	c = p->line[p->i];
	p->i++;
	while (p->line[p->i] != c && p->line[p->i])
		p->m->val[p->m->j] = put_char(p->m->val[p->m->j], p->line[p->i++]);
	if (p->line[p->i] == c)
		p->i++;
	return (p);
}

t_list	*qts_help(t_list *p)
{
	char	c;

	c = p->line[p->i];
	p->i++;
	p->m->val[p->m->j] = pr_strdup("");
	while (p->line[p->i] != c && p->line[p->i])
		p->m->val[p->m->j] = put_char(p->m->val[p->m->j], p->line[p->i++]);
	p->m->j++;
	if (p->line[p->i] == c)
		p->i++;
	return (p);
}
