/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:43:59 by darabi            #+#    #+#             */
/*   Updated: 2015/12/04 14:22:14 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				check_first(char *str, char *src, char **line)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (str[i] == src[i])
		i++;
	if (str[i] == '-' && !src[i])
	{
		*line = ft_strnew(ft_strlen(str));
		++i;
		while (str[i])
			(*line)[j++] = str[i++];
		return (1);
	}
	return (-1);
}

static int		initialization(char *str, int *i, int *j)
{
	*j = 0;
	*i = 0;
	if (!str || !str[*i])
		return (-1);
	while (str[*i] != '-')
		++*i;
	++*i;
	return (1);
}

int				check_scnd_struc(char *str, char *src, char **line)
{
	int			i;
	int			j;

	if (initialization(str, &i, &j) == -1)
		return (-1);
	while (str[i] && str[i] == src[j])
	{
		++j;
		++i;
	}
	if (!src[j] && !str[i])
	{
		*line = ft_strnew(ft_strlen(str));
		j = 0;
		while (str[j] != '-')
		{
			(*line)[j] = str[j];
			++j;
		}
		(*line)[j] = '\0';
		return (1);
	}
	return (-1);
}
