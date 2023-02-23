/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:22:08 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/18 23:24:01 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*grep_files(t_list *p)
{
	if (p->line[p->i] == '<' && p->error != 1)
		p = south_face(p);
	if (p->line[p->i] == '>' && p->error != 1)
		p = north_face(p);
	if (p->error != 1)
		p->i = skip_space(p->line, p->i);
	return (p);
}

t_list	*north_face(t_list *p)
{
	p = north_errors(p);
	if (p->error != 1)
	{
		if (p->line[p->i] == '>' && p->line[p->i + 1] == '>')
			p = north_help(p, APPENDD);
		else if (p->line[p->i] == '>' && check_ffile(p->line[p->i + 1])
			&& p->line[p->i + 1])
			p = north_help(p, OUTFILEE);
	}
	return (p);
}

t_list	*south_face(t_list *p)
{
	p = south_errors(p);
	if (p->error != 1)
	{
		if (p->line[p->i] == '<' && p->line[p->i + 1] == '<')
			p = south_herdo(p);
		else if (p->line[p->i] == '<' && check_ffile(p->line[p->i + 1]))
			p = south_inpu(p);
	}
	return (p);
}

t_list	*north_errors(t_list *p)
{
	int	i;

	if (p->error != 1)
	{
		i = p->i;
		if ((p->line[i] == '>' && p->line[i + 1] == '<') && p->error != 1)
			p = erorat("syntax error", p);
		while ((p->line[i] == '>' || p->line[i] == '<') && p->error != 1)
			i++;
		if (((i - p->i) >= 3) && p->error != 1)
			p = erorat("syntax error", p);
		i = skip_space(p->line, i);
		if ((p->line[i] == '>' || p->line[i] == '<' || p->line[i] == '|'
				|| p->line[i] == '\0' || p->line[i] == '\n') && p->error != 1)
			p = erorat("syntax error", p);
	}
	return (p);
}

t_list	*south_errors(t_list *p)
{
	int	i;

	if (p->error != 1)
	{
		i = p->i;
		if (p->line[i] == '<' && p->line[i + 1] == '>')
			p = erorat("syntax error", p);
		while (p->line[i] == '<' && p->error != 1)
			i++;
		if (((i - p->i) >= 3) && p->error != 1)
			p = erorat("syntax error", p);
		i = skip_space(p->line, i);
		if ((p->line[i] == '>' || p->line[i] == '<' || p->line[i] == '|'
				|| p->line[i] == '\0' || p->line[i] == '\n') && p->error != 1)
			p = erorat("syntax error", p);
	}
	return (p);
}
