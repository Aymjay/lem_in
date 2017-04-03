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

void	changing(t_lem_list **begin, t_lem_list **list)
{
	t_lem_list *temp;

	temp = *begin;
	while (temp->next != *list)
		temp = temp->next;
	temp->next = NULL;
	erraz(list);
}

void	help_display(void)
{
	ft_printf("\t {green}{u}COMMAND LIST{eoc} {green}:{eoc}\n");
	ft_printf("-h : display command list\n");
	ft_printf("-a : display all ways\n");
	ft_printf("-b : display only the best way\n");
	ft_printf("-e : display errors with more precision\n");
	ft_printf("-n : display count\n");
	exit(0);
}

int		main_parsing_second(char **tab_rooms, char *cmd, \
		t_lem_list **begin, t_lem_list **list)
{
	char		**tab_tubes;

	tab_tubes = parsing_tubes(tab_rooms, list);
	if (!tab_tubes || !tab_tubes[0])
	{
		if (ft_strcmp(cmd, "-e") == 0)
			ft_printf("{b}any tubes defined{eoc}\n");
		else
			ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	changing(begin, list);
	if (cmd)
		starting(tab_rooms, tab_tubes, cmd, *begin);
	else
		starting(tab_rooms, tab_tubes, NULL, *begin);
	return (1);
}

int		main_parsing(t_lem_list *list, char **line, int argc, char **argv)
{
	char		**tab_rooms;
	t_lem_list	*begin;

	if (ft_atoi(list->str) <= 0)
	{
		if (argc == 2 && ft_strcmp(argv[1], "-e") == 0)
			ft_printf("{b}invalid ant number{eoc}\n");
		else
			ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	all_to_list(line, &list);
	begin = list;
	if (!(tab_rooms = parsing_rooms(&list, argv[1])))
	{
		if (argc == 2 && ft_strcmp(argv[1], "-e") == 0)
			ft_printf("{b}invalid room define{eoc}\n");
		else
			ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	return (main_parsing_second(tab_rooms, argv[1], &begin, &list));
}

int		main(int argc, char **argv)
{
	char		*line;
	t_lem_list	*list;

	if (argc == 2 && ft_strcmp(argv[1], "-h") == 0)
		help_display();
	line = ft_strnew(1);
	if (get_next_line(0, &line) <= 0)
	{
		if (argc == 2 && ft_strcmp(argv[1], "-e") == 0)
			ft_printf("{b}Read error{eoc}\n");
		else
			ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	if (!line)
	{
		if (argc == 2 && ft_strcmp(argv[1], "-e") == 0)
			ft_printf("{b}Blank file{eoc}\n");
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	list = lem_new_list(line);
	return (main_parsing(list, &line, argc, argv));
}
