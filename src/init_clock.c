/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:33:12 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 22:41:21 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_clock(char **argv, t_clock_inf *time)
{
	if (!(convert_argv(&(time -> die_time), argv[1])
			&& convert_argv(&(time -> eat_time), argv[2])
			&& convert_argv(&(time -> rest_time), argv[3])))
		return (0);
	return (1);
}

int	convert_argv(long int *local, char *str)
{
	*local = string_to_int(str, 0);
	if (*local == -1)
	{
		return (0);
	}
	return (1);
}

long int	string_to_int(char *str_digit, long int num)
{
	if (*str_digit == 0)
	{
		return (num);
	}
	num = (num * 10) + (str_digit[0] - '0');
	if (num % 10 != (str_digit[0] - '0'))
	{
		return (-1);
	}
	return (string_to_int(&(str_digit[1]), num));
}
