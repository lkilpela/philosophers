/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:52:08 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 22:56:40 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Gets the current time in milliseconds
int get_time(void)
{
	struct timeval	tv;

    if (gettimeofday(&tv, NULL == 1))
		return (1);
	return (tv.tv_sec * 1000000 + tv.tv_usec / 1000);    
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
	unsigned long long	result;
	int					sign;
	int					digit;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' 
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!((unsigned char)*str >= '0' && (unsigned char)*str <= '9'))
			return (-1);
		digit = *str - '0';
		if (ft_is_overflow(result, sign, digit))
			return (0);
		result = (result * 10) + (digit * sign);
		str++;
	}
	return (result);
}
