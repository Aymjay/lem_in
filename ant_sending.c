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

int			just_walking(t_graff ****tab, int i, int ant, int j)
{
	if ((*tab)[j][i]->data == 0)
		return (1);
	((*tab)[j][i + 1]->count)++;
	(*tab)[j][i + 1]->data = (*tab)[j][i]->data;
	(*tab)[j][i]->count = 0;
	(*tab)[j][i]->data = 0;
	ft_printf("L%d-%s ", (*tab)[j][i + 1]->data, (*tab)[j][i + 1]->name);
	return (just_walking(tab, i - 1, ant, j));
}

int			walking(t_graff ****tab, int i, int ant, int j)
{
	if (i == 0 && ((*tab)[j][i]->count) != 0)
	{
		((*tab)[j][i + 1]->count)++;
		((*tab)[j][i]->count)--;
		(*tab)[j][i + 1]->data = ant - (*tab)[j][i]->count;
		ft_printf("L%d-%s ", (*tab)[j][i + 1]->data, (*tab)[j][i + 1]->name);
		return (1);
	}
	if ((*tab)[j][i]->count == 0)
		return (1);
	((*tab)[j][i + 1]->count)++;
	(*tab)[j][i + 1]->data = (*tab)[j][i]->data;
	(*tab)[j][i]->count = 0;
	(*tab)[j][i]->data = 0;
	ft_printf("L%d-%s ", (*tab)[j][i + 1]->data, (*tab)[j][i + 1]->name);
	return (walking(tab, i - 1, ant, j));
}

int			multi_sending(t_graff ****tab, int ant, t_graff *ending)
{
	int i;
	int j;
	int h;

	i = 0;
	j = 0;
	h = 0;
	while ((*tab)[j] && (*tab)[j][0] && (*tab)[j][1])
	{
		while ((*tab)[j][i] != ending)
			++i;
		h = i;
		--i;
		while (i > 0 && (*tab)[j][i]->count == 0)
			--i;
		if (j != 0 && h > (*tab)[0][0]->count)
			just_walking(tab, i, ant, j);
		else
			walking(tab, i, ant, j);
		++j;
		i = 0;
	}
	ft_printf("\n");
	return (1);
}

int			sending_ant(t_graff ****tab, int ant, int ending, int *i)
{
	while ((*tab)[0][ending]->count != ant)
	{
		multi_sending(tab, ant, (*tab)[0][ending]);
		++*i;
	}
	return (1);
}
