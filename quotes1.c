/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:01:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/24 19:36:19 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	single_inqts(char *line)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			i++;
			while (line[i] != '"' && line[i])
			{
				if (line[i] == '\'')
					d++;
				i++;
			}
			if (line[i] == '\0')
				d = 0;
		}
		if (line[i])
			i++;
	}
	return (d);
}

int	double_inqts(char *line)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'' && line[i])
			{
				if (line[i] == '"')
					d++;
				i++;
			}
			if (line[i] == '\0')
				d = 0;
		}
		if (line[i])
			i++;
	}
	return (d);
}

t_list	*qts_check(t_list *p)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = 0;
	while (p->line[i])
	{
		if (p->line[i] == '\'')
			s++;
		if (p->line[i] == '"')
			d++;
		i++;
	}
	d -= double_inqts(p->line);
	s -= single_inqts(p->line);
	if (d % 2 || s % 2)
	{
		ft_err("Minishell :", " unclosed", " quotes\n", 1);
		p->error = 1;
	}
	return (p);
}
