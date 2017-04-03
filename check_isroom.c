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

int					coord_comp(char *first, char *scnd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (first[i] != ' ')
		i++;
	while (scnd[j] != ' ')
		j++;
	while (scnd[j] && scnd[j] == first[i])
	{
		++i;
		++j;
	}
	if (!scnd[j])
		return (1);
	return (0);
}

int					name_comp(char *first, char *scnd)
{
	int i;

	i = 0;
	while (first[i] == scnd[i] && first[i] != ' ')
		++i;
	if (first[i] == ' ' && scnd[i] == ' ')
		return (1);
	return (0);
}

int					checking_for_same(char **tab, int number, char *str)
{
	int i;

	i = 0;
	if (!tab[0] | !tab[1])
		return (0);
	if (!str)
		return (1);
	while (i < number)
	{
		if (name_comp(tab[i], str) == 1)
			return (0);
		if (coord_comp(tab[i], str) == 1)
			return (0);
		++i;
	}
	++number;
	return (checking_for_same(tab, number, tab[number]));
}

int					isroom_next(char *line, int i)
{
	if (ft_issign(line[i]) == 1)
		++i;
	if (ft_isdigit(line[i]) == 1)
	{
		while (ft_isdigit(line[i]) == 1)
			++i;
		if (line[i] != ' ')
			return (-1);
		++i;
	}
	if (ft_issign(line[i]) == 1)
		++i;
	if (ft_isdigit(line[i]) == 1)
	{
		while (ft_isdigit(line[i]) == 1)
			++i;
		if (line[i] != '\0')
			return (-1);
		return (1);
	}
	return (-1);
}

int					isroom(char *line)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "##start") == 0)
		return (3);
	if (ft_strcmp(line, "##end") == 0)
		return (4);
	if (line[i] == '#')
		return (2);
	if (line[i] == ' ' || line[i] == 'L')
		return (-1);
	while (line[i] && line[i] != ' ')
		++i;
	if (!line[i])
		return (0);
	++i;
	return (isroom_next(line, i));
}
