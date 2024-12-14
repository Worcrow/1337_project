/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 07:05:56 by oel-asri          #+#    #+#             */
/*   Updated: 2024/12/13 05:35:41 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i++])
		;
	return (i);
}

static char	*ft_strdup(char *str)
{
	size_t	len;
	char	*ret;

	len = -1;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[++len])
		ret[len] = str[len];
	ret[len] = '\0';
	return (ret);
}

static char	*ft_itoa(int n)
{
	size_t	len;
	int		temp;
	char	*res;

	temp = n;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n > 0)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	while (str1[++i])
		res[j++] = str1[i];
	i = -1;
	while (str2[++i])
		res[j++] = str2[i];
	res[j] = '\0';
	return (res);
}

char	*create_sem_name(char *sem_name, int nb)
{
	char	*tmp;
	char	*ret;

	tmp = ft_itoa(nb);
	if (!tmp)
		return (NULL);
	ret = ft_strjoin(sem_name, tmp);
	if (!ret)
		return (NULL);
	free(tmp);
	return (ret);
}
