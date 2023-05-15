/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:57:22 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 21:25:41 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*program_cycle(void *data);
static void	check_status(t_tabletop *table);
static void	isolated_hunger(t_philo *philo);

void	begin_all(t_tabletop *tabletop)
{
	int	counter;

	counter = -1;
	while (++counter < tabletop->quantity)
		pthread_create(&(tabletop->philo[counter]->ted), 0, \
						program_cycle, tabletop->philo[counter]);
	check_status(tabletop);
}

static void	*program_cycle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2)
		usleep(750);
	if (philo->right == philo->left)
		isolated_hunger(philo);
	while (!get_cycle_status(philo))
	{
		if (pick_up_fork(philo) || start_eating(philo) \
				|| fell_sleepy(philo) || deep_thoughts(philo))
			break ;
	}
	let_go_fork(philo);
	return (0);
}

static void	isolated_hunger(t_philo *philo)
{
	print_in_term(philo, FORK);
	pthread_mutex_unlock(philo->writing);
	mutex_sleep(philo->time->die_time + 10);
	return ;
}

static void	check_status(t_tabletop *tabletop)
{
	int	counter;

	counter = 0;
	while (!(tabletop->simul_end))
	{
		usleep(100);
		if (get_gratification(tabletop->philo[counter]) == tabletop->quantity)
		{
			pthread_mutex_lock(&(tabletop->writing));
			tabletop->simul_end = 1;
			pthread_mutex_unlock(&(tabletop->writing));
			break ;
		}
		if (get_time() - (tabletop->philo[counter])->last_bite \
				>= tabletop->philo[counter]->time->die_time)
		{
			print_in_term(tabletop->philo[counter], DEATH);
			tabletop->simul_end = 1;
			pthread_mutex_unlock(&(tabletop->writing));
			break ;
		}
		counter = (counter + 1) % tabletop->quantity;
	}
}
