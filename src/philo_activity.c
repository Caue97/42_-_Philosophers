/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:43:01 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 22:09:44 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	if (print_in_term(philo, FORK))
	{
		return (1);
	}
	pthread_mutex_unlock(philo->writing);
	if (print_in_term(philo, FORK))
	{
		return (1);
	}
	pthread_mutex_unlock(philo->writing);
	return (0);
}

void	let_go_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

int	deep_thoughts(t_philo *philo)
{
	print_in_term(philo, THINKING);
	pthread_mutex_unlock(philo->writing);
	checking_death(philo);
	return (0);
}

int	start_eating(t_philo *philo)
{
	set_last_bite(philo);
	if (print_in_term(philo, EATING))
	{
		return (1);
	}
	pthread_mutex_unlock(philo->writing);
	if (philo->bites == philo->satiation)
	{
		set_gratification(philo);
	}
	mutex_sleep(philo->time->eat_time);
	checking_death(philo);
	let_go_fork(philo);
	return (0);
}

int	fell_sleepy(t_philo *philo)
{
	print_in_term(philo, SLEEPY);
	pthread_mutex_unlock(philo->writing);
	mutex_sleep(philo->time->rest_time);
	checking_death(philo);
	return (0);
}
