/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:11:59 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/23 22:36:21 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*dollar_init(t_list *p)
{
	p->l = 1;
	p->k = 1;
	p->i = 0;
	if (p->line2)
	{
		while (p->line2[p->i])
		{
			if (p->line2[p->i] == '$' && p->line2[p->i + 1] == '$')
				p->line = put_char(p->line, p->line2[p->i++]);
			else if (p->line2[p->i] == '\'')
				p = dollar_init1(p);
			else if (p->line2[p->i] == '"')
				p = dollar_init2(p);
			else if (p->line2[p->i] == '$' && p->line2[p->i + 1] != '$')
				p = grep_dollar(p);
			else if (p->line2[p->i] && p->line2[p->i] != '"'
				&& p->line2[p->i] != '\'')
				p->line = put_char(p->line, p->line2[p->i++]);
		}
	}
	return (p);
}

t_list	*dollar_init1(t_list *p)
{
	p->line = put_char(p->line, p->line2[p->i++]);
	if (p->line2[p->i] == '\'')
	{
		p->line = put_char(p->line, p->line2[p->i++]);
		p->l = 0;
	}
	else
		p->l = 1;
	while (p->line2[p->i] != '\'' && p->line2[p->i] && p->l)
	{
		if (p->line2[p->i] != '\'' && p->line2[p->i])
			p->line = put_char(p->line, p->line2[p->i++]);
		if (p->line2[p->i] == '\'')
		{
			p->line = put_char(p->line, p->line2[p->i++]);
			break ;
		}
	}
	return (p);
}

t_list	*dollar_init2(t_list *p)
{
	p->line = put_char(p->line, p->line2[p->i++]);
	if (p->line2[p->i] == '"')
	{
		p->line = put_char(p->line, p->line2[p->i++]);
		p->k = 0;
	}
	else
		p->k = 1;
	while (p->line2[p->i] != '"' && p->line2[p->i] && p->k)
	{
		if (p->line2[p->i] != '"' && p->line2[p->i] != '$' && p->line2[p->i])
			p->line = put_char(p->line, p->line2[p->i++]);
		if (p->line2[p->i] == '$')
			p = grep_dollar(p);
		if (p->line2[p->i] == '"')
		{
			p->line = put_char(p->line, p->line2[p->i++]);
			break ;
		}
	}
	return (p);
}
