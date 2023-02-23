/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:14:33 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/22 22:22:22 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	pr_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

int	pr_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	pr_strncmpp(char *str1, char *str2)
{
	size_t	i;

	if (pr_strlen(str1) != pr_strlen(str2))
		return (2);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}
