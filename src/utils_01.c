/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:51:22 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 20:49:44 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	free_and_check_data(void **data, long int num);

void	**alloc_data(long int quant, long int ptr_size, long int size)
{
	long int	counter;
	void		**data;
	void		*buff;

	counter = 0;
	data = malloc(quant * ptr_size);
	if (data == 0)
		return (0);
	while (counter < quant)
	{
		buff = malloc(size);
		if (buff == 0)
		{
			data[counter] = 0;
			free_data(data, counter + 1);
			return (0);
		}
		data[counter] = buff;
		counter += 1;
	}
	return (data);
}

long int	get_time(void)
{
	t_time	time;

	gettimeofday(&time, 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	free_tabletop(t_tabletop *tabletop)
{
	mutex_destroyer(tabletop);
	free(tabletop->forks);
	free_and_check_data((void **)(tabletop->philo), tabletop->quantity);
}

static void	free_and_check_data(void **data, long int num)
{
	if (data != 0)
		free_data(data, num);
}

void	free_data(void **data, long int num)
{
	int	counter;

	counter = 0;
	while (counter < num)
	{
		free(data[counter]);
		counter += 1;
	}
	free(data);
}
