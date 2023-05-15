/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:01:24 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 21:01:25 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	get_cycle_status(t_philo *philo)
{
	int	philo_status;

	pthread_mutex_lock(philo->eating);
	philo_status = *(philo->simul_end);
	pthread_mutex_unlock(philo->eating);
	return (philo_status);
}

long int	get_gratification(t_philo *philo)
{
	long int	gratification;

	pthread_mutex_lock(philo->eating);
	gratification = *(philo->gratification);
	pthread_mutex_unlock(philo->eating);
	return (gratification);
}

long int	get_last_bite(t_philo *philo)
{
	long int	last_bite;

	pthread_mutex_lock(philo->eating);
	last_bite = philo->last_bite;
	pthread_mutex_unlock(philo->eating);
	return (last_bite);
}

int	get_bite(t_philo *philo)
{
	int	chomps;

	pthread_mutex_lock(philo->eating);
	chomps = philo->bites;
	pthread_mutex_unlock(philo->eating);
	return (chomps);
}
