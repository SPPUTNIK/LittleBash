/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessamad <abdessamad@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:43:29 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/21 22:43:59 by abdessamad       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int num)
{
	if (num == 3)
	{
		rl_on_new_line();
		rl_redisplay();
		g_glo.exit = 131;
	}
	else if (num == 2)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		// rl_replace_line("", 0);
		rl_redisplay();
		g_glo.exit = 130;
	}
}

void	han_her(int num)
{
	if (num == SIGINT && g_glo.k == 1)
	{
		g_glo.k = 2;
		close(0);
	}
}
