/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:57:23 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 02:31:10 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

void	the_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	herror(char *str)
{
	perror(str);
	exit(1);
	return (0);
}

char	*ft_access(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (access(str[i], F_OK) == -1)
			i++;
		if (access(str[i], F_OK) == 0)
			return (str[i]);
	}
	free(str);
	herror("no commands");
	exit(1);
}

char	*one_line(char	*paths, char *str, char *sstr)
{
	(void)paths;
	free(str);
	return (sstr);
}
