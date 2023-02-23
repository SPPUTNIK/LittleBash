/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_herdo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:41:07 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 02:31:05 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*grep_dollar_h(t_list *p)
{
	char	*dollo;
	int		j;

	dollo = pr_strdup("");
	p->i++;
	if (!pr_isalnum(p->line2[p->i]) && p->line2[p->i] != '_')
		p = dollar_help_h(p);
	else if (pr_alph(p->line2[p->i]) || p->line2[p->i] == '_')
	{
		while (pr_isalnum(p->line2[p->i]) && p->line2[p->i]
			&& p->line2[p->i] != '$')
			dollo = put_char(dollo, p->line2[p->i++]);
	}
	else
		p->i++;
	j = 0;
	if (check_dollar_h(p, dollo))
	{
		while (p->valo[j])
			p->line = put_char(p->line, p->valo[j++]);
		free(p->valo);
	}
	free(dollo);
	return (p);
}

int	check_dollar_h(t_list *p, char *dollo)
{
	int		i;
	int		j;
	t_var	*tmp;

	i = 0;
	tmp = p->var;
	if (dollo == NULL)
		return (0);
	j = pr_strlen(dollo);
	while (p->var != NULL)
	{
		if (pr_strncmpp(p->var->key, dollo) == 0)
		{
			p->valo = pr_strdup(p->var->value);
			p->var = tmp;
			return (1);
		}
		p->var = p->var->next;
	}
	p->var = tmp;
	return (0);
}

t_list	*dollar_help_h(t_list *p)
{
	int		j;
	char	*exit;

	j = 0;
	p->i -= 1;
	exit = ft_itoa(g_glo.exit);
	if (p->line2[p->i] == '$' && p->line2[p->i + 1] == '?')
	{
		while (exit[j])
			p->line = put_char(p->line, exit[j++]);
		p->i += 2;
	}
	else
	{
		while (j < 2)
		{
			p->line = put_char(p->line, p->line2[p->i++]);
			j++;
		}
	}
	free(exit);
	return (p);
}
