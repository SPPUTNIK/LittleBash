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

void	my_envr(t_var **t_env, t_pipe *pi)
{
	t_var	*tmp;
	int		i;

	i = 0;
	tmp = *t_env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	pi->envr = malloc(sizeof(char *) * (i + 1));
	if (!pi->envr)
		return ;
	i = 0;
	tmp = *t_env;
	while (tmp)
	{
		pi->envr[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	pi->envr[i] = 0;
}

int	other_cmds(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp)
{
	pi->save_inp_out[0] = dup(0);
	pi->save_inp_out[1] = dup(1);
	if (pi->size == 1)
		ft_one_node(pi, b, t_env, t_exp);
	else if (pi->size > 1)
	{
		if (b->m->val[0])
		{
			if (ft_multiple_node(pi, b, t_env, t_exp))
				return (-1);
		}
		else if (b->m->ouf[0] || b->m->her[0])
			ft_redirection(t_env, pi, b);
	}
	g_glo.k = 1;
	dup2(pi->save_inp_out[0], 0);
	dup2(pi->save_inp_out[1], 1);
	unlink("/tmp/herc");
	return (0);
}

int	check_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (0);
	else if (!ft_strcmp(cmd, "cd"))
		return (0);
	else if (!ft_strcmp(cmd, "pwd"))
		return (0);
	else if (!ft_strcmp(cmd, "env"))
		return (0);
	else if (!ft_strcmp(cmd, "exit"))
		return (0);
	else if (!ft_strcmp(cmd, "unset"))
		return (0);
	else if (!ft_strcmp(cmd, "export"))
		return (0);
	else
		return (1);
}

void	builtins(t_var **t_env, t_var **t_exp, t_list *b)
{
	char	*pwd;

	if (!pr_strncmpp(b->m->val[0], "echo"))
		ft_echo(b);
	else if (!pr_strncmpp(b->m->val[0], "cd"))
		ft_cd(b, t_env, t_exp);
	else if (!pr_strncmpp(b->m->val[0], "pwd"))
	{
		pwd = pr_strdup(ft_pwd());
		printf("%s\n", pwd);
		free(pwd);
	}
	else if (!pr_strncmpp(b->m->val[0], "env"))
		ft_env(t_env);
	else if (!pr_strncmpp(b->m->val[0], "exit"))
		ft_exit(b);
	else if (!pr_strncmpp(b->m->val[0], "unset"))
		ft_unset(t_env, t_exp, b);
	else if (!pr_strncmpp(b->m->val[0], "export"))
		ft_export(t_env, t_exp, b);
    g_glo.exit = 0;
}
