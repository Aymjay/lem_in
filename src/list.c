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

t_lem_list			*lem_new_list(const char *line)
{
	t_lem_list *new_list;

	new_list = malloc(sizeof(t_lem_list));
	if (!line)
		return (NULL);
	new_list->str = ft_strdup(line);
	new_list->next = NULL;
	return (new_list);
}

void				new_to_list(const char *line, t_lem_list **list)
{
	t_lem_list *new_list_part;
	t_lem_list *begin;

	begin = *list;
	new_list_part = malloc(sizeof(t_lem_list));
	if (!line)
		return ;
	new_list_part->str = ft_strdup(line);
	new_list_part->next = NULL;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = new_list_part;
	(*list) = begin;
}

void				all_to_list(char **line, t_lem_list **list)
{
	while (get_next_line(0, line) > 0)
	{
		if (ft_strcmp(*line, "##EOF") == 0)
			return ;
		new_to_list(*line, list);
	}
}

int					list_func(t_lem_list *list, int f(char *str))
{
	int i;

	i = 0;
	while (list)
	{
		if (f(list->str) == 1)
			++i;
		else if (f(list->str) < 1)
			break ;
		list = list->next;
	}
	return (i);
}

int					list_func_tube(t_lem_list *list, char **tab, \
					int f(char *str, char **tab))
{
	int i;

	i = 0;
	while (list)
	{
		if (f(list->str, tab) == 1)
			++i;
		else if (f(list->str, tab) < 1)
			break ;
		list = list->next;
	}
	return (i);
}
