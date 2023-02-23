/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:12:28 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/25 02:31:25 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_msg(void)
{
	printf("exit\n");
	ft_err("minishell: exit", " ", \
	": too many arguments\n", 1);
}

static int	ft_exit2(t_list *b)
{
	printf("exit\n");
	ft_err("minishell: exit: ", b->m->val[1], \
	": numeric argument required\n", 255);
	return (255);
}

void	ft_exit(t_list *b)
{
	int	i;
	int	j;

	i = 1;
	while (b->m->val[i])
	{
		j = 0;
		while (b->m->val[i][j])
		{
			if (i == 1 && ft_isdigit(b->m->val[i][j]))
				exit(ft_exit2(b));
			j++;
		}
		i++;
	}
	if (b->m->val[1])
		g_glo.exit = ft_atoi(b->m->val[1]);
	else
		g_glo.exit = 0;
	if (count_files(b->m->val) > 2)
		return (error_msg());
	printf("exit\n");
	exit(g_glo.exit);
}
