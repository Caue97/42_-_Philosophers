/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:32:52 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 22:50:10 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_philo(t_philo **philo, t_tabletop *tabletop, t_clock_inf *clock)
{
	int			counter;
	long int	g_time;

	counter = 0;
	g_time = get_time();
	while (counter < tabletop -> quantity)
	{
		philo[counter]->id = counter;
		philo[counter]->bites = 0;
		philo[counter]->writing = &(tabletop->writing);
		philo[counter]->gratification = &(tabletop->gratification);
		philo[counter]->satiation = tabletop->satiation;
		philo[counter]->g_time = g_time;
		philo[counter]->last_bite = g_time;
		philo[counter]->simul_end = &(tabletop->simul_end);
		philo[counter]->right = &(tabletop->forks[counter]);
		philo[counter]->left = &(tabletop->forks[(counter + 1) \
							% tabletop->quantity]);
		philo[counter]->time = clock;
		philo[counter]->eating = &(tabletop->mutex_ex);
		counter += 1;
	}
	return (1);
}
