/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:51:17 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/02 17:43:38 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cast_s;

	cast_s = (char *)s;
	i = 0;
	while (cast_s[i])
	{
		if (cast_s[i] == (char)c)
			return (&cast_s[i]);
		i++;
	}
	if (c == '\0')
		return (&cast_s[i]);
	return (NULL);
}
