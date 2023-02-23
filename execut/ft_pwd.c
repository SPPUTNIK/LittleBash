/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:25 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/25 17:56:13 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_pwd(void)
{
	char	cmd[1024];
	char	*ptr;

	ptr = getcwd(cmd, sizeof(cmd));
	g_glo.exit = 0;
	if (!ptr)
	{
		printf("Current directory: getcwd: cannot access parent directories");
		return (NULL);
	}
	return (ptr);
}
