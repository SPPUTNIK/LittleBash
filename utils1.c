/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:40 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/18 23:24:58 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	pr_wnb2(char *str, char c)
{
	int		*ij;
	int		i;

	ij = malloc(sizeof(int) * 2);
	ij[0] = 0;
	ij[1] = 0;
	while (str[ij[0]])
	{
		if (str[ij[0]] == '|')
			ij[0]++;
		if (str[ij[0]] == '"' || str[ij[0]] == '\'')
			ij = wnbb_beta(ij, str);
		if (wnb_check(str, ij, c))
		{
			ij[0]++;
			ij[1]++;
		}
		if (str[ij[0]] || str[ij[0]] == '|')
			ij[0]++;
	}
	i = ij[1];
	free(ij);
	return (i);
}

int	pr_wnbb(char *str, char c)
{
	int		*ij;
	int		i;

	ij = malloc(sizeof(int) * 2);
	ij[0] = 0;
	ij[1] = 0;
	while (str[ij[0]])
	{
		if (str[ij[0]] == '"' || str[ij[0]] == '\'')
			ij = wnbb_beta(ij, str);
		if (str[ij[0]] != '<' || str[ij[0]] != '>')
			ij[0]++;
		if ((str[0] != c && ij[0] == 0) || (str[ij[0]] != c
				&& str[ij[0] - 1] == c))
		{
			ij[0]++;
			ij[1]++;
		}
		else if (str[ij[0]])
			ij[0]++;
	}
	i = ij[1];
	free(ij);
	return (i);
}

int	skip_space(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

t_list	*erorat(char *str, t_list *p)
{
	printf("%s\n", str);
	p->error = 1;
	return (p);
}

int	pr_counterr(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c && pr_isalnum(str[i + 1]))
			j++;
		i++;
	}
	return (j);
}
