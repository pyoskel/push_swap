/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 01:48:46 by pabartoc          #+#    #+#             */
/*   Updated: 2026/06/24 17:47:01 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "libft.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_length_valid(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		len++;
		i++;
	}
	if (len > 10)
		return (0);
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	has_duplicate(char **args, int i, long num)
{
	int		j;
	long	check_num;

	j = 0;
	while (j < i)
	{
		check_num = ft_atol(args[j]);
		if (num == check_num)
			return (1);
		j++;
	}
	return (0);
}

int	is_input_valid(char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i] != NULL)
	{
		if (!is_number(args[i]) || !is_length_valid(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (has_duplicate(args, i, num))
			return (0);
		i++;
	}
	return (1);
}
