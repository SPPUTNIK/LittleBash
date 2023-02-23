/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:40:36 by abel-bou        #+#    #+#             */
/*   Updated: 2022/07/19 14:51:24 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	her_doc_befor_last(t_list *b, t_list *p, int count_her_doc)
{
	int		i;

	i = 0;
	while (i < count_her_doc - 1)
	{
		p->line2 = readline("> ");
		if (!p->line2)
			i++;
		else if (!ft_strcmp(b->m->her[i], p->line2))
			i++;
		if (p->line2)
			free(p->line2);
	}
	return (0);
}

void	ret_herdo(t_list *p, t_pipe *pi, int i)
{
	char	*all_doc;

	if (i == 0)
	{
		p->line = pr_strdup("");
		p = dollar_init_h(p);
	}
	else if (i == 1)
		p->line = ft_substr(p->line2, 0, pr_strlen(p->line2));
	all_doc = ft_strjoin(p->line, "\n");
	free(p->line);
	ft_putstr_fd(all_doc, pi->fd[0]);
	free(all_doc);
}

int	last_her_doc(t_list *b, t_list *p, t_pipe *pi, int count_her_doc)
{
	while (b->m->her[count_her_doc - 1])
	{
		p->line2 = readline("> ");
		if (p->line2 == NULL || !p->line2)
			return (1);
		if (ft_strcmp(p->line2, b->m->her[count_her_doc - 1]))
		{
			if (ft_strcmp(p->line2, b->m->her[count_her_doc - 1]))
				ret_herdo(p, pi, b->m->hflag);
		}
		else
			count_her_doc++;
		free(p->line2);
	}
	dup(g_glo.ffdd);
	return (0);
}

static int	ft_ret_her(t_list *p)
{
	free(p);
	signal(SIGINT, SIG_IGN);
	return (-1);
}

int	her_doc(t_list *b, t_pipe *pi, t_var *t_env)
{
	int		count_her_doc;
	t_list	*p;

	signal(SIGINT, han_her);
	g_glo.k = 1;
	p = malloc(sizeof(t_list));
	p = struct_builtins(p, t_env);
	pi->fd[0] = open("/tmp/herc", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pi->fd[0] < 0)
		return (ft_ret_her(p));
	count_her_doc = count_files(b->m->her);
	if (her_doc_befor_last(b, p, count_her_doc))
		return (ft_ret_her(p));
	if (last_her_doc(b, p, pi, count_her_doc))
		return (ft_ret_her(p));
	close(pi->fd[0]);
	pi->fd[0] = open("/tmp/herc", O_RDWR, 0644);
	if (pi->fd[0] < 0)
		return (ft_ret_her(p));
	free(p);
	signal(SIGINT, SIG_IGN);
	return (0);
}
