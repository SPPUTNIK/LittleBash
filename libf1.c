/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:13:30 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 18:09:15 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	pr_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*pr_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	s2 = (char *)malloc(pr_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*put_char(char *s, char c)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		s = pr_strdup("");
	i = pr_strlen(s);
	len = i + 2;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	pr_alph(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
