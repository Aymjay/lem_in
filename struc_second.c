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

int			ending_modif(t_graff **begin, char *str,\
			t_graff **looking_for, int j)
{
	t_graff *temp;
	int		i;

	i = 0;
	(*begin)->data = j;
	while ((*begin)->next[i])
	{
		temp = (*begin)->next[i];
		if (ft_strcmp(str, temp->name) == 0)
		{
			*looking_for = temp;
			temp->w = -2;
			return (1);
		}
		if (temp->data != j)
			ending_modif(&temp, str, looking_for, j);
		++i;
	}
	return (0);
}

int			all_check(t_graff **begin, char *str, t_graff **looking_for, int j)
{
	t_graff *temp;
	int		i;

	i = 0;
	(*begin)->data = j;
	while ((*begin)->next[i])
	{
		temp = (*begin)->next[i];
		if (ft_strcmp(str, temp->name) == 0)
		{
			*looking_for = temp;
			return (1);
		}
		if (temp->data != j)
			all_check(&temp, str, looking_for, j);
		++i;
	}
	return (0);
}
