/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:33:37 by felcaue-          #+#    #+#             */
/*   Updated: 2023/05/14 22:48:47 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define DEATH "is dead"
# define EATING	"is eating"
# define THINKING "is thinking"
# define SLEEPY "is sleeping"
# define FORK "has taken a fork"

typedef struct timeval	t_time;

typedef struct s_clock_inf
{
	long int		die_time;
	long int		eat_time;
	long int		rest_time;
}	t_clock_inf;

typedef struct s_philo
{
	pthread_t		ted;
	int				id;
	int				bites;
	int				*simul_end;
	long int		last_bite;
	long int		g_time;
	long int		satiation;
	long int		*gratification;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	t_clock_inf		*time;
}	t_philo;

typedef struct s_tabletop
{
	t_philo			**philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	mutex_ex;
	int				simul_end;
	long int		quantity;
	long int		satiation;
	long int		gratification;
}	t_tabletop;

///////////////////////////////////////////////
///////////        Functions        ///////////
///////////////////////////////////////////////

// main.c

int			check_if_number(char **str);

// init_clock.c

int			init_clock(char **argv, t_clock_inf *time);
long int	string_to_int(char *str_digit, long int num);
int			convert_argv(long int *local, char *str);

// init_tabletop.c

int			init_tabletop(char **argv, int argc, t_tabletop *tabletop);

// init_mutex.c

int			init_mutex(t_tabletop *tabletop);

// init_philo.c

int			init_philo(t_philo **philo, t_tabletop *tabletop, \
								t_clock_inf *clock);

// start.c

void		begin_all(t_tabletop *tabletop);

// get.c

int			get_cycle_status(t_philo *philo);
long int	get_gratification(t_philo *philo);
long int	get_last_bite(t_philo *philo);
int			get_bite(t_philo *philo);

// set.c

void		set_last_bite(t_philo *philo);
void		set_gratification(t_philo *philo);

// philo_activity.c

int			pick_up_fork(t_philo *philo);
void		let_go_fork(t_philo *philo);
int			deep_thoughts(t_philo *philo);
int			start_eating(t_philo *philo);
int			fell_sleepy(t_philo *philo);

// utils_01.c

void		**alloc_data(long int quant, long int ptr_size, \
								long int size);
long int	get_time(void);
void		free_tabletop(t_tabletop *tabletop);
void		free_data(void **data, long int num);

// utils_02.c

void		mutex_destroyer(t_tabletop *tabletop);
void		checking_death(t_philo *philo);
int			print_in_term(t_philo *philo, char *philo_status);
void		mutex_sleep(long int time);
void		philo_wait(t_tabletop *tabletop);

#endif
