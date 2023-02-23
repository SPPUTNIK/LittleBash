/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:48:55 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/25 02:29:04 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_err(char *minishell, char *name, char *msg, int exit)
{
	ft_putstr(minishell);
	ft_putstr(name);
	ft_putstr(msg);
	g_glo.exit = exit;
}
