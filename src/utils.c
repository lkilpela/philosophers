/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:34:04 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 13:50:49 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_overflow(int result, int sign, int digit)
{
	int max;
	int min;

	max = 2147483647;
	min = -2147483648;
	if ((sign == 1 && result > (max - digit) / 10)
		|| (sign == -1 && result < (min + digit) / 10))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (ft_is_overflow(result, sign, digit))
			return (0);
		result = (result * 10) + (digit * sign);
		str++;
	}
	return (result);
}
