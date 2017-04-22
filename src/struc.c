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

t_graff		*create_struc_lem(t_graff **begin, char *str, char **tab_tubes)
{
	t_graff *new_graff;
	int		i;

	i = 0;
	while ((*begin)->next[i] != NULL)
		++i;
	new_graff = malloc(sizeof(t_graff));
	new_graff->name = ft_strdup(str);
	new_graff->data = 0;
	new_graff->count = 0;
	new_graff->weigth = -1;
	new_graff->w = -1;
	(*begin)->next[i] = new_graff;
	(*begin)->next[i + 1] = NULL;
	new_graff->next = malloc(tube_count(str, tab_tubes) * sizeof(	t_graff));
	new_graff->next[0] = *begin;
	new_graff->next[1] = NULL;
	return (new_graff);
}

void		linking_room(t_graff **room_1, t_graff **room_2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*room_1)->next[i])
		++i;
	while ((*room_2)->next[j])
		++j;
	(*room_1)->next[i] = *room_2;
	(*room_2)->next[j] = *room_1;
	(*room_1)->next[i + 1] = NULL;
	(*room_2)->next[j + 1] = NULL;
}

static void	increment(int *i, t_graff **temp)
{
	*temp = NULL;
	++*i;
}

static int	initialize(int *i, t_graff **temp, t_graff *begin)
{
	*i = 0;
	*temp = NULL;
	if (!begin)
		return (0);
	return (1);
}

void		create_struc(t_graff **begin, t_graff **begin_cpy, \
			char **tab_rooms, char ***tab_tubes)
{
	int			i;
	static int	j = 1;
	t_graff		*temp;
	char		*str;

	if (initialize(&i, &temp, *begin) == 0)
		return ;
	while ((*tab_tubes)[i])
	{
		if (check_first((*tab_tubes)[i], (*begin)->name, &str) != -1 ||\
		check_scnd_struc((*tab_tubes)[i], (*begin)->name, &str) != -1)
		{
			(*tab_tubes)[i][0] = '\0';
			all_check(begin_cpy, str, &temp, j);
			++j;
			if (temp)
				linking_room(begin, &temp);
			else
			{
				temp = create_struc_lem(begin, str, *tab_tubes);
				create_struc(&temp, begin_cpy, tab_rooms, tab_tubes);
			}
		}
		increment(&i, &temp);
	}
}
