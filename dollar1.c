/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:08:16 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 02:31:02 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_list	*grep_dollar(t_list *p)
{
	char	*dollo;
	int		j;

	dollo = pr_strdup("");
	if (p->line2[p->i] == '$')
		p->i++;
	if (!pr_isalnum(p->line2[p->i]) && p->line2[p->i] != '_')
		p = dollar_help(p);
	else if ((pr_alph(p->line2[p->i]) || p->line2[p->i] == '_'))
	{
		while (pr_isalnum(p->line2[p->i]) && p->line2[p->i])
			dollo = put_char(dollo, p->line2[p->i++]);
	}
	j = 0;
	if (check_dollar(p, dollo))
	{
		p->line = put_char(p->line, '"');
		while (p->valo[j])
			p->line = put_char(p->line, p->valo[j++]);
		p->line = put_char(p->line, '"');
		free(p->valo);
	}
	free(dollo);
	return (p);
}

int	check_dollar(t_list *p, char *dollo)
{
	int		i;
	int		j;
	t_var	*tmp;

	i = 0;
	tmp = p->var;
	if (dollo == NULL)
		return (0);
	j = pr_strlen(dollo);
	while (tmp != NULL)
	{
		if (pr_strncmpp(tmp->key, dollo) == 0)
		{
			p->valo = pr_strdup(tmp->value);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_list	*dollar_help(t_list *p)
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
