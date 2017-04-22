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

char			*check_second_name(char *str, int count, char **src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!src[count])
		return (NULL);
	while (str[i] != '-')
		++i;
	++i;
	while (str[i] == src[count][j])
	{
		++j;
		++i;
	}
	if (!str[i] && src[count][j] == ' ')
		return (src[count]);
	++count;
	return (check_second_name(str, count, src));
}

char			*check_first_name(char *str, int count, char **src)
{
	int i;

	i = 0;
	if (!src[count])
		return (NULL);
	while (str[i] == src[count][i])
		i++;
	if (str[i] == '-' && src[count][i] == ' ')
		return (src[count]);
	++count;
	return (check_first_name(str, count, src));
}

int				looking_for(char *tube, char **tab_rooms)
{
	if (check_first_name(tube, 0, tab_rooms) == NULL)
		return (0);
	if (check_second_name(tube, 0, tab_rooms) == NULL)
		return (0);
	if (ft_strcmp(check_first_name(tube, 0, tab_rooms),\
		check_second_name(tube, 0, tab_rooms)) == 0)
		return (0);
	return (1);
}

int				istube(char *line, char **tab_rooms)
{
	int i;

	i = 0;
	if (line[i] == '#' || line[i] == 'L')
		return (2);
	if (line[i] == '-')
		return (0);
	while (line[i] && line[i] != '-')
		i++;
	if (!line[i] || looking_for(line, tab_rooms) == 0)
		return (0);
	return (1);
}

char			**parsing_tubes(char **tab_rooms, t_lem_list **list)
{
	char	**tab;
	int		test;
	int		j;

	j = 0;
	if (!*list)
		return (NULL);
	tab = malloc((list_func_tube(*list, tab_rooms, &istube) + 1)\
			* sizeof(char *));
	test = istube((*list)->str, tab_rooms);
	while (*list)
	{
		if (test == 1)
		{
			tab[j++] = ft_strdup((*list)->str);
			*list = (*list)->next;
		}
		else if (test == 2)
			*list = (*list)->next;
		else if (test == 0)
			return (tab);
		if (*list)
			test = istube((*list)->str, tab_rooms);
	}
	return (tab);
}
