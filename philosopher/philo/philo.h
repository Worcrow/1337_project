/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:10:58 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 09:16:11 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define PHILO_MAX 200

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	bool			*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}					t_philo;
typedef struct s_data
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	bool			dead;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_data;

void	init_data(t_data *program, t_philo *philos, \
					pthread_mutex_t *forks, char *argv[]);

int		thread_create(t_data *program, pthread_mutex_t *forks);
void	*monitor(void *pointer);
void	*philo_routine(void *pointer);

void	eat(t_philo *philo);
void	think(t_philo *philo);

int		dead_loop(t_philo *philo);
int		check_if_all_ate(t_philo *philos);
int		check_if_dead(t_philo *philos);
bool	is_dead(t_philo *philo, size_t time_to_die);

void	destory_all(char *str, t_data *program, pthread_mutex_t *forks);

long	ft_atol(char *str);
int		ft_usleep(size_t milliseconds, t_philo *philo);
void	print_message(char *str, t_philo *philo, int id);
size_t	get_current_time(void);
void	error(char *message);

#endif
