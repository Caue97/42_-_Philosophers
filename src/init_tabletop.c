/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabletop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:02:18 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 20:25:53 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_tabletop(char **argv, int argc, t_tabletop *tabletop)
{
	if (!(convert_argv(&(tabletop->quantity), argv[0])))
	{
		return (0);
	}
	if (argc == 6)
	{
		convert_argv(&(tabletop->satiation), argv[4]);
	}
	else
	{
		tabletop->satiation = -2;
	}
	tabletop->simul_end = 0;
	tabletop->gratification = 0;
	tabletop->forks = malloc(tabletop->quantity * sizeof(pthread_mutex_t));
	tabletop->philo = (t_philo **)alloc_data(tabletop->quantity, \
			sizeof(t_philo *), sizeof(t_philo));
	if (!(tabletop->philo && tabletop->forks))
	{
		free_tabletop(tabletop);
		return (0);
	}
	return (1);
}
