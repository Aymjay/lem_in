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

int			best(t_graff *ending, int nb, t_graff ****tab)
{
	t_graff		*temp;
	int			i;

	i = 0;
	if (ending->weigth == 0)
		return (1);
	while (ending->next[i])
	{
		temp = ending->next[i];
		if (temp->weigth == (nb - 1))
		{
			(*tab)[0][nb - 1] = temp;
			best(temp, nb - 1, tab);
		}
		++i;
	}
	return (0);
}

int			resolve(t_graff **begin, int nb)
{
	int		i;

	i = 0;
	if ((*begin)->weigth <= nb && (*begin)->weigth != -1)
		return (0);
	(*begin)->weigth = nb;
	while ((*begin)->next[i])
	{
		(*begin)->data = 0;
		resolve(&(*begin)->next[i], nb + 1);
		++i;
	}
	return (0);
}
