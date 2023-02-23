/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:42:08 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/19 22:10:06 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_wnb(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			i = skip_quots(str, i, str[i]);
			j++;
		}
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c))
		{
			i++;
			j++;
		}
		if (str[i])
			i++;
	}
	return (j);
}

static void	ft_free(char **str, int wnbr)
{
	int	i;

	i = 0;
	while (i < wnbr)
	{
		free(str[i]);
		i++;
	}
}

int	utils_alloc(int i, char c, char *s)
{
	while (s[i] != c && s[i])
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
		}
		i++;
	}
	return (i);
}

static void	alloc(char **sp, char *s, char c, int wnbr)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	while (j < wnbr - 1)
	{
		while ((s[i] == c) && s[i] != '\0')
			i++;
		index = i;
		i = utils_alloc(i, c, s);
		sp [j] = ft_substr(s, index, i - index);
		if (!sp[j])
		{
			ft_free(sp, j);
			break ;
		}
		j++;
	}
	sp[j] = NULL;
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		wnbr;

	if (s == NULL)
		return (NULL);
	wnbr = ft_wnb(s, c) + 1;
	str = malloc(sizeof(char *) * wnbr);
	if (str == NULL)
		return (NULL);
	alloc(str, s, c, wnbr);
	return (str);
}
