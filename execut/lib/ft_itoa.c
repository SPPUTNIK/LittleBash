/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:52:30 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/17 03:50:37 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	len_n(int n)
{
	int				i;
	unsigned int	k;

	k = n;
	i = 1;
	if (n < 0)
	{
		k = -k;
		i++;
	}
	while (k >= 10)
	{
		k = k / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*alloc;
	unsigned int	k;

	k = n;
	if (n < 0)
		k = k * (-1);
	i = len_n(n);
	alloc = malloc(sizeof(char) * i + 1);
	if (!alloc)
		return (NULL);
	alloc[i] = '\0';
	while (i > 0)
	{
		i--;
		alloc[i] = (k % 10) + '0';
		k = k / 10;
		if (n < 0)
			alloc[0] = '-';
	}
	return (alloc);
}
