/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:17:23 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/19 14:33:04 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*grep_command(t_list *p)
{
	while (check_cmd(p->line[p->i], 1) && p->line[p->i])
	{
		if (check_cmd(p->line[p->i], 2) && p->line[p->i])
			p = grep_cmddd(p);
		p->i = skip_space(p->line, p->i);
	}
	return (p);
}

t_list	*grep_cmddd(t_list *p)
{
	p->m->val[p->m->j] = pr_strdup("");
	while (check_cmd(p->line[p->i], 2) && p->line[p->i] != '\0')
	{
		if (p->line[p->i] == '"')
			p = l_quotes(p);
		else if (p->line[p->i] == '\'')
			p = l_quotes(p);
		else if (check_cmd(p->line[p->i], 2) && p->line[p->i] != '\0')
			p->m->val[p->m->j] = put_char(p->m->val[p->m->j], p->line[p->i++]);
	}
	p->m->j++;
	return (p);
}

int	check_cmd(char c, int i)
{
	if (i == 1)
	{
		if (c == '<' || c == '>' || c == '|')
			return (0);
	}
	if (i == 2)
	{
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0'
			|| c == '<' || c == '>' || c == '|')
			return (0);
	}
	return (1);
}
