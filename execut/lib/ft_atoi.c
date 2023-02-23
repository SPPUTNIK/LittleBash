/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:55:37 by abel-bou          #+#    #+#             */
/*   Updated: 2022/08/21 17:47:41 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_twentyfive_line(const char *str, int i, int sign)
{
	int		num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		num;
	int		count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			count++;
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	num = ft_twentyfive_line(str, i, sign);
	if (count >= 2)
		return (0);
	return (num);
}
