/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 03:17:04 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

void	freee_more(t_mini *m)
{
	int	i;

	i = 0;
	while (m->ouf[i])
		free(m->ouf[i++]);
	i = 0;
	while (m->inf[i])
		free(m->inf[i++]);
	i = 0;
	while (m->her[i])
		free(m->her[i++]);
	i = 0;
	while (m->val[i])
		free(m->val[i++]);
	free(m->ouf);
	free(m->inf);
	free(m->her);
	free(m->val);
	free(m->otype);
	free(m->open);
}

void	the_freeee(t_list *p)
{
	t_mini	*tmp;

	while (p->m)
	{
		freee_more(p->m);
		tmp = p->m;
		p->m = p->m->next;
		free(tmp);
	}
}

static void	smia(int ac, char **av)
{	
	(void)ac;
	(void)av;
	signal(SIGINT, handler);
	signal(SIGTSTP, handler);
	signal(3, handler);
}

int	main(int ac, char **av, char **env)
{
	t_list	*p;
	t_list	*tmp;
	t_var	*t_env;
	t_var	*t_exp;

	smia(ac, av);
	cpy_env(&t_env, &t_exp, env);
	p = malloc(sizeof(t_list));
	while (1)
	{
		p = parser(t_env, p);
		tmp = p;
		g_glo.ffdd = dup(0);
		if (p->ext == 1)
			exit(g_glo.exit);
		if (p->errorx != 1)
		{
			if (p->error != 1)
				execution(&t_env, &t_exp, tmp);
			the_freeee(p);
		}
	}
	return (g_glo.exit);
}
