/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:15:44 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/23 16:25:44 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*struct_builtins(t_list *p, t_var *var)
{
	p->var = var;
	return (p);
}

int	ret_pipe(t_list *p)
{
	free(p->line2);
	ft_err("minishell:", " syntax error near unexpected token", " `|'\n", 258);
	p->errorx = 1;
	return (1);
}

int	check_piipe(t_list *p)
{
	char	c;
	int		i;

	i = skip_space(p->line2, 0);
	if (p->line2[i] == '|')
		return (ret_pipe(p));
	while (p->line2[i])
	{
		if (p->line2[i] == '"' || p->line2[i] == '\'')
		{
			c = p->line2[i++];
			while (p->line2[i] != c && p->line2[i])
				i++;
		}
		if (p->line2[i] == '|')
		{
			i++;
			i = skip_space(p->line2, i);
			if (p->line2[i] == '|' || p->line2[i] == '\0'
				|| p->line2[i] == '\n')
				return (ret_pipe(p));
		}
		i++;
	}
	return (0);
}

int	*wnbb_beta(int *ij, char *str)
{
	char	cc;

	cc = str[ij[0]];
	ij[0]++;
	while (str[ij[0]] != cc && str[ij[0]])
		ij[0]++;
	if (str[ij[0]])
		ij[0]++;
	ij[1]++;
	return (ij);
}

int	wnb_check(char *str, int *ij, char c)
{
	if ((str[0] != c && ij[0] == 0) || (str[ij[0]] != c
			&& str[ij[0] - 1] == c) || (str[0] != '<' && ij[0] == 0)
		|| (str[ij[0]] != '<' && str[ij[0] - 1] == '<')
		|| (str[0] != '>' && ij[0] == 0) || (str[ij[0]] != '>'
			&& str[ij[0] - 1] == '>'))
	{
		return (1);
	}
	return (0);
}
