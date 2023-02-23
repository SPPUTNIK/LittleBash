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

void	no_need_proccess(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp)
{
	if (b->m->inf[0] || b->m->her[0])
		dup2(pi->fd[0], 0);
	if (b->m->ouf[0])
		dup2(pi->fd[1], 1);
	builtins(t_env, t_exp, b);
}

void	ft_is_directory(char *value)
{
	DIR	*directory;

	directory = opendir(value);
	if (value[0] == '/' && !directory)
		ft_err("minishell :", value, ": No such file or directory\n", 127);
	else if (directory && ft_strchr(value, '/'))
	{
		closedir(directory);
		ft_err("minishell :", value, ": Is a directory\n", 126);
	}
	else if (!directory && ft_strchr(value, '/'))
		ft_err("minishell :", value, ": Not a directory\n", 126);
	else
		ft_err("minishell :", value, ": command not found\n", 127);
}

void	need_new_proccess(t_var **var, t_pipe *pi, t_list *b)
{
	if (g_glo.k == 2)
		return ;
	pi->pid_proc[pi->i] = fork();
	if (pi->pid_proc[pi->i] == 0)
	{
		signal(SIGINT, handler);
		if (b->m->inf[0] || b->m->her[0])
			dup2(pi->fd[0], 0);
		if (b->m->ouf[0])
			dup2(pi->fd[1], 1);
		if (b->m->val[0] && execve(get_pathss(*var, b->m->val[0]), \
		b->m->val, pi->envr) == -1)
			ft_is_directory(b->m->val[0]);
		exit(g_glo.exit);
	}
}

void	ft_execut_cmd(t_var **t_env, t_var **t_exp, t_pipe *pi, t_list *b)
{
	t_mini	*tmp;

	pi->i = 0;
	while (b->m)
	{
		if (!b->m->val[0] && !b->m->her[0] && !b->m->ouf[0] && !b->m->inf[0])
			return ;
		else
			if (other_cmds(pi, b, t_env, t_exp))
				break ;
		pi->i++;
		freee_more(b->m);
		tmp = b->m;
		b->m = b->m->next;
		free(tmp);
	}
}

void	execution(t_var **t_env, t_var **t_exp, t_list *b)
{
	t_pipe	*pi;
	int		pro;

	signal(SIGINT, SIG_IGN);
	pi = malloc(sizeof(t_pipe));
	if (!pi)
		return ;
	pi = pi_init(pi, b);
	if (!pi->pip_fd)
		return ;
	pro = ft_connect_proccess(pi);
	if (pro == -1)
		return ;
	my_envr(t_env, pi);
	ft_execut_cmd(t_env, t_exp, pi, b);
	ft_close(pi);
	pi->i = 0;
	while (pi->i < pi->size)
		waitpid(pi->pid_proc[pi->i++], &g_glo.exit, 0);
	free_the_pi(pi);
	free(pi);
	if (WIFEXITED(g_glo.exit))
		g_glo.exit = WEXITSTATUS(g_glo.exit);
	signal(SIGINT, handler);
}
