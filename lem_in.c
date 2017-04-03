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

void		tab_way(t_graff ****tab, t_graff *ending, char *cmd, int j)
{
	t_graff	*temp;
	int		i;

	i = 0;
	while (ending->next[i])
	{
		if (ending->next[i] != (*tab)[0][0])
		{
			temp = ending->next[i];
			(*tab)[j + 1] = NULL;
			(*tab)[j] = malloc((temp->w + 3) * sizeof(t_graff));
			(*tab)[j][0] = 0;
			(*tab)[j][temp->w + 1] = ending;
			other_way(temp, temp->w, tab, j);
			if (!(*tab)[j] || !(*tab)[j][0] || (*tab)[j][0] != (*tab)[0][0])
				free((*tab)[j]);
			else
				++j;
		}
		++i;
	}
	(*tab)[j] = NULL;
	if (cmd && (ft_strcmp(cmd, "-b") == 0 || ft_strcmp(cmd, "-a") == 0))
		display_tab(*tab, cmd, ending);
}

int			starting_third_part(t_graff **begin, t_graff *ending,\
							char *cmd, t_graff ****tab)
{
	int i;

	i = 0;
	tab_way(tab, ending, cmd, 1);
	if (cmd && ft_strcmp(cmd, "-r") == 0)
		ft_printf("{red}");
	sending_ant(tab, (*begin)->count, ending->weigth, &i);
	if (cmd && ft_strcmp(cmd, "-r") == 0)
		ft_printf("{eoc}");
	if (cmd && ft_strcmp(cmd, "-n") == 0)
		ft_printf("Done with {green}%d{eoc} turn(s)\n", i);
	exit(0);
	return (1);
}

int			starting_second_part(t_graff **begin, t_graff *ending,\
							char *cmd, int nb)
{
	t_graff ***tab;

	resolve(begin, 0);
	tab = malloc((nb + 2) * sizeof(t_graff));
	tab[0] = malloc((ending->weigth + 2) * sizeof(t_graff));
	tab[0][ending->weigth] = ending;
	tab[0][ending->weigth + 1] = NULL;
	best(ending, ending->weigth, &tab);
	resolve_w(begin, ending, 0);
	return (starting_third_part(begin, ending, cmd, &tab));
}

t_graff		*new_begin(char *name, int count)
{
	t_graff		*begin;

	begin = malloc(sizeof(t_graff));
	begin->name = ft_strdup(name);
	begin->count = count;
	begin->w = -1;
	begin->weigth = -1;
	return (begin);
}

int			starting(char **tab_rooms, char **tab_tubes,\
				char *cmd, t_lem_list *l_begin)
{
	t_graff		*begin;
	t_graff		*ending;
	int			nb;

	ending = NULL;
	changing_tab(&tab_rooms);
	begin = new_begin(tab_rooms[0], ft_atoi(l_begin->str));
	begin->next = malloc(sizeof(t_graff)\
		* tube_count(tab_rooms[0], tab_tubes));
	begin->next[0] = NULL;
	create_struc(&begin, &begin, tab_rooms, &tab_tubes);
	ending_modif(&begin, tab_rooms[1], &ending, (begin->data + 1));
	if (!ending)
	{
		if (ft_strcmp(cmd, "-e") == 0)
			ft_printf("{b}Impossible mazerunner{eoc}\n");
		else
			ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	print_all(l_begin);
	nb = tube_count(ending->name, tab_tubes);
	free_tab(&tab_rooms);
	free_tab(&tab_tubes);
	return (starting_second_part(&begin, ending, cmd, nb));
}
