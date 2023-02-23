/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:25:44 by abdessamad        #+#    #+#             */
/*   Updated: 2022/08/23 16:25:54 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_utils_echo(t_list *b)
{
	int	count;
	int	i;
	int	j;

	count = 1;
	j = 1;
	while (b->m->val[j])
	{
		if (!ft_strncmp(b->m->val[j], "-n", 2))
		{
			i = 1;
			while (b->m->val[j][i])
			{
				if (b->m->val[j][i] != 'n')
					return (count);
				else
					i++;
			}
			if (!b->m->val[j++][i])
				count++;
		}
		else
			return (j);
	}
	return (count);
}

int	without_arg(t_list *b)
{
	if (b->wn == 2)
	{
		printf("\n");
		return (0);
	}
	return (-1);
}

static int	ft_echo2(t_list *b, int i)
{
	while (b->m->val[i])
	{
		ft_putstr_fd(b->m->val[i], STDOUT_FILENO);
		if (b->m->val[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (i);
}

void	ft_echo(t_list *b)
{
	int	i;

	if (!without_arg(b))
		return ;
	i = ft_utils_echo(b);
	if (ft_utils_echo(b) == 1)
		i = ft_echo2(b, i);
	else
	{
		while (b->m->val[i])
		{
			ft_putstr_fd(b->m->val[i], STDOUT_FILENO);
			if (b->m->val[i + 1])
				ft_putstr_fd(" ", STDOUT_FILENO);
			i++;
		}
	}
}
