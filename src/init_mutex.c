/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:00:34 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/12 00:10:07 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_mutex(t_tabletop *tabletop)
{
	int	counter;

	counter = 0;
	while (counter < tabletop->quantity)
	{
		if (pthread_mutex_init(&(tabletop->forks[counter]), 0))
			return (0);
		counter += 1;
	}
	if (pthread_mutex_init(&(tabletop->writing), 0))
	{
		return (0);
	}
	if (pthread_mutex_init(&(tabletop->mutex_ex), 0))
	{
		return (0);
	}
	return (1);
}
