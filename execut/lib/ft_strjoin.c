/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:19:58 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/20 03:01:12 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	j = 0;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	while (s2[j])
	{
			str[i] = s2[j];
			i++;
			j++;
	}
	str[i] = '\0';
	return (str);
}
