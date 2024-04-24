/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:52:08 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/24 22:52:26 by lkilpela         ###   ########.fr       */
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
