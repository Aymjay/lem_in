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

int		resolve_w(t_graff **begin, t_graff *ending, int nb)
{
	int		i;

	i = 0;
	if (((*begin)->w <= nb && (*begin)->w != -1) || *begin == ending)
		return (0);
	(*begin)->w = nb;
	while ((*begin)->next[i])
	{
		(*begin)->data = 0;
		resolve_w(&(*begin)->next[i], ending, nb + 1);
		++i;
	}
	return (0);
}

int		check_same_way(t_graff *temp, t_graff ***tab)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		while (tab[i] && tab[i][j])
		{
			if (tab[i][j] == temp)
				return (0);
			++j;
		}
		j = 1;
		++i;
	}
	return (1);
}

int		other_way(t_graff *ending, int nb, t_graff ****tab, int j)
{
	t_graff *temp;
	int		i;

	i = 0;
	if (ending->w == 0)
	{
		(*tab)[j][0] = ending;
		return (1);
	}
	if (check_same_way(ending, *tab) == 0)
		return (0);
	while (ending->next[i])
	{
		temp = ending->next[i];
		if (check_same_way(temp, *tab) == 1 && (temp->w == (nb - 1)))
		{
			(*tab)[j][nb] = ending;
			other_way(temp, temp->w, tab, j);
		}
		++i;
	}
	return (0);
}
