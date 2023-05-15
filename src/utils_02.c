/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:43:32 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 22:48:39 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	mutex_destroyer(t_tabletop *tabletop)
{
	int	counter;

	counter = 0;
	while (counter < tabletop->quantity)
	{
		pthread_mutex_destroy(&(tabletop->forks[counter]));
		counter += 1;
	}
	pthread_mutex_destroy(&(tabletop->writing));
	pthread_mutex_destroy(&(tabletop->mutex_ex));
}

void	checking_death(t_philo *philo)
{
	if (get_time() - philo->last_bite >= philo->time->die_time)
	{
		print_in_term(philo, DEATH);
		*(philo->simul_end) = 1;
		pthread_mutex_unlock(philo->writing);
	}
}

int	print_in_term(t_philo *philo, char *philo_status)
{
	long int	time_holder;

	pthread_mutex_lock(philo->writing);
	if (!get_cycle_status(philo))
	{
		time_holder = get_time() - philo->g_time;
		printf("%ld %d %s\n", time_holder,
			philo->id + 1, philo_status);
		return (0);
	}
	pthread_mutex_unlock(philo->writing);
	return (1);
}

void	mutex_sleep(long int time)
{
	long int	time_holder;

	time_holder = get_time();
	usleep((time - 1) * 1000);
	while (get_time() - time_holder < time)
	{
		usleep(25);
	}
}

void	philo_wait(t_tabletop *tabletop)
{
	int	counter;

	counter = 0;
	while (counter < tabletop->quantity)
	{
		pthread_join((tabletop->philo[counter])->ted, 0);
		counter += 1;
	}
}
