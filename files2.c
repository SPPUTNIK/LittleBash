/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:26:56 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/23 00:18:07 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*north_help(t_list *p, int type)
{
	p->m->ouf[p->m->oo] = pr_strdup("");
	if (type == APPENDD)
		p->i = skip_space(p->line, p->i + 2);
	if (type == OUTFILEE)
		p->i = skip_space(p->line, p->i + 1);
	p = north_help2(p, type);
	return (p);
}

t_list	*north_help22(t_list *p)
{
	char	c;

	c = p->line[p->i];
	p->i++;
	while (p->line[p->i] != c && p->line[p->i])
		p->m->ouf[p->m->oo] = put_char(p->m->ouf[p->m->oo], p->line[p->i++]);
	if (p->line[p->i] == c)
		p->i++;
	return (p);
}

t_list	*north_help2(t_list *p, int type)
{
	p->i = skip_space(p->line, p->i);
	while (check_ffile(p->line[p->i]) && p->line[p->i])
	{
		if (p->line[p->i] == '"' || p->line[p->i] == '\'')
			p = north_help22(p);
		else if (check_mfile(p->line[p->i]) && p->line[p->i])
			p->m->ouf[p->m->oo] = put_char(p->m->ouf[p->m->oo], \
			p->line[p->i++]);
		else
			break ;
	}
	p->m->otype[p->m->oo] = type;
	if (p->m->ouf[p->m->oo][0] != 0)
	{
		p->m->oo++;
		p->m->open[p->m->op] = OUFF;
		p->m->op++;
	}
	return (p);
}

int	check_ffile(char c)
{
	if (c == '?' || c == '\\' || c == '/' || c == '*'
		|| c == ';' || c == '&' || c == '(' || c == ')'
		|| c == '`' || c == '{' || c == '\n' || c == '|' || c == '\0')
	{
		return (0);
	}
	return (1);
}

int	check_mfile(char c)
{
	if (c == '?' || c == '\\' || c == '/' || c == '*'
		|| c == ';' || c == '&' || c == '(' || c == ')'
		|| c == '<' || c == '>' || c == '`' || c == '{'
		|| c == ' ' || c == '\t' || c == '\n' || c == '|'
		|| c == '\0' || c == '"' || c == '\'')
	{
		return (0);
	}
	return (1);
}
