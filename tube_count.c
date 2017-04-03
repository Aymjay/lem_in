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

int			first_name(char *str, char *src)
{
	int i;

	if (!src)
		return (0);
	i = 0;
	while (str[i] == src[i])
		i++;
	if (src[i] == '-' && !str[i])
		return (1);
	return (0);
}

int			second_name(char *str, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[i] != '-')
		++i;
	++i;
	while (src[i] && src[i] == str[j])
	{
		++j;
		++i;
	}
	if (!src[i] && !str[j])
		return (1);
	return (0);
}

int			tube_count(char *str, char **tab_tubes)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (tab_tubes[i])
	{
		if (first_name(str, tab_tubes[i]) == 1 ||\
		second_name(str, tab_tubes[i]) == 1)
			++count;
		++i;
	}
	return (count);
}
