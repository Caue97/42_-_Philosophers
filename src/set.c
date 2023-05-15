/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:50:52 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 21:12:04 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_last_bite(t_philo *philo)
{
	pthread_mutex_lock(philo->eating);
	philo->bites += 1;
	philo->last_bite = get_time();
	pthread_mutex_unlock(philo->eating);
}

void	set_gratification(t_philo *philo)
{
	pthread_mutex_lock(philo->eating);
	*(philo->gratification) += 1;
	pthread_mutex_unlock(philo->eating);
}
