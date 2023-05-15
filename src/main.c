/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:33:20 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 22:59:52 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	init(int argc, char **argv, \
						t_tabletop *tabletop, t_clock_inf *clock);

int	main(int argc, char *argv[])
{
	t_clock_inf	clock;
	t_tabletop	tabletop;

	if ((argc < 5 || argc > 6)
		|| check_if_number(argv + 1))
	{
		printf("How to use: ./philo <philo_number> <time_to_die> \
<time_to_hunger> <time_sleeping> <number_of_times_to_eat>\n");
		return (1);
	}
	if (init(argc, argv + 1, &tabletop, &clock))
	{
		free_tabletop(&tabletop);
		return (1);
	}
	if (tabletop.quantity > 0)
		begin_all(&tabletop);
	philo_wait(&tabletop);
	free_tabletop(&tabletop);
	return (0);
}

// 1 for failure | 0 for success
static int	init(int argc, char **argv, \
						t_tabletop *tabletop, t_clock_inf *clock)
{
	if (init_clock(argv, clock)
		&& init_tabletop(argv, argc, tabletop)
		&& init_mutex(tabletop)
		&& init_philo(tabletop->philo, tabletop, clock))
		return (0);
	return (1);
}

int	check_if_number(char **string)
{
	int	counter01;
	int	counter02;

	if (string == 0 || *string == 0 || **string == 0)
		return (1);
	counter01 = 0;
	while (string[counter01])
	{
		counter02 = 0;
		while (string[counter01][counter02])
		{
			if (string[counter01][counter02] < '0' || \
					string[counter01][counter02] > '9')
				return (1);
			counter02 += 1;
		}
		counter01 += 1;
	}
	return (0);
}
