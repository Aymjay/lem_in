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

int					begin_ending(char ***tab, t_lem_list **list,\
					int g, char *cmd)
{
	if (g == 3)
		g = 0;
	else
		g = 1;
	while (*list && ((*list)->str)[0] == '#')
		*list = (*list)->next;
	if (*list && (*list)->str && isroom((*list)->str) == 1)
	{
		(*tab)[g] = ft_strdup((*list)->str);
		*list = (*list)->next;
	}
	else
	{
		if (ft_strcmp(cmd, "-e") == 0)
			ft_printf("{b}Begin or ending error{eoc}\n");
		else
			ft_putstr_fd("ERROR\n", 2);
		exit(0);
	}
	return (1);
}

static void			parsing_rooms_part(char ***tab, t_lem_list **list, int *j)
{
	(*tab)[*j] = ft_strdup((*list)->str);
	++*j;
	(*tab)[*j] = NULL;
	(*list) = (*list)->next;
}

static int			parsing_rooms_part_another(t_lem_list **list,\
					char ***tab, int *j, int *test)
{
	*j = 2;
	(*list) = (*list)->next;
	if (!*list)
		return (0);
	*tab = malloc((list_func(*list, &isroom) + 2) * sizeof(char *));
	(*tab)[0] = NULL;
	(*tab)[1] = NULL;
	(*tab)[2] = NULL;
	*test = isroom((*list)->str);
	return (1);
}

char				**parsing_rooms(t_lem_list **list, char *cmd)
{
	int		j;
	int		test;
	char	**tab;

	if (parsing_rooms_part_another(list, &tab, &j, &test) == 0)
		return (NULL);
	while (*list)
	{
		if (test == 1)
			parsing_rooms_part(&tab, list, &j);
		else if (test == 2)
			*list = (*list)->next;
		else if (test == 3 || test == 4)
			test = begin_ending(&tab, list, test, cmd);
		else if (test == -1)
			return (NULL);
		else if (test == 0)
			break ;
		if (*list)
			test = isroom((*list)->str);
	}
	if (checking_for_same(tab, 0, tab[0]) == 0)
		return (NULL);
	return (tab);
}
