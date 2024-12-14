/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:19:07 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 09:37:03 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <sys/mman.h>
# include <signal.h>
# include <stdbool.h>

typedef struct s_data
{
	pthread_t		pt_finished;
	size_t			close_all;
	size_t			nbr;
	size_t			sleep_time;
	size_t			eat_time;
	size_t			death_time;
	size_t			nb_meals;
	size_t			start_time;
	sem_t			*finished;
	sem_t			*death;
	char			**forks_name;
	sem_t			**forks;
	sem_t			*kill_all;
	sem_t			*time;
	sem_t			*mutex;
}	t_data;

typedef struct s_philo
{
	pthread_t			pt_time;
	int					philo_pid;
	bool				dead;
	bool				full;
	size_t				philo_id;
	size_t				eaten_num;
	size_t				last_meal;
	sem_t				*left_fork;
	sem_t				*right_fork;
	struct s_philo		*next;
	struct s_philo		*prev;
	t_data				*data;
}	t_philo;

int		set_data(t_data *data, char **argv, int argc);
int		set_philo(t_philo **list, t_data *data);
t_philo	*lst_new(size_t i, t_data *data);
void	f_lstclear(t_philo **philo, size_t i);
long	ft_atol(char *str);
int		philo_create(t_philo **philo);
void	philo_job(t_philo *philo);
void	print_state(char *str, t_philo *philo);
size_t	get_time(size_t delta_time);
int		check_over(t_philo *philo);
void	*check_time(void *arg);
void	kill_all(t_philo *philo);
void	*all_ate(void *arg);
void	f_unlink(t_philo **philo);
char	*create_sem_name(char *sem_name, int nb);
void	print_error(char *message);
void	check_args(t_data *list, int argc);
void	free_forks(t_data *list, int size);
bool	is_dead(t_philo *philo);
void	ft_usleep(size_t milliseconds, t_philo *philo);

#endif