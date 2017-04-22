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

void	erraz(t_lem_list **list)
{
	t_lem_list *temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}

int		lst_cmp_second(t_lem_list **list)
{
	if (ft_strcmp((*list)->str, "##red") == 0)
	{
		ft_printf("%s\n", (*list)->str);
		ft_printf("\033[31m");
		return (1);
	}
	else if (ft_strcmp((*list)->str, "##RED") == 0)
	{
		ft_printf("\033[31m");
		return (1);
	}
	else if (ft_strcmp((*list)->str, "##BLUE") == 0)
	{
		ft_printf("{blue}");
		return (1);
	}
	else if (ft_strcmp((*list)->str, "##blue") == 0)
	{
		ft_printf("%s\n", (*list)->str);
		ft_printf("{blue}");
		return (1);
	}
	return (0);
}

int		lst_cmp(t_lem_list **list)
{
	if (ft_strcmp((*list)->str, "##green") == 0)
	{
		ft_printf("%s\n", (*list)->str);
		ft_printf("\033[32m");
		return (1);
	}
	else if (ft_strcmp((*list)->str, "##GREEN") == 0)
	{
		ft_printf("\033[32m");
		return (1);
	}
	else if (ft_strcmp((*list)->str, "##eoc") == 0)
	{
		ft_printf("\033[00m");
		ft_printf("%s\n", (*list)->str);
		return (1);
	}
	else if (ft_strcmp((*list)->str, "##EOC") == 0)
	{
		ft_printf("\033[00m");
		return (1);
	}
	return (lst_cmp_second(list));
}

void	print_all(t_lem_list *list)
{
	while (list)
	{
		if (lst_cmp(&list) == 0)
			ft_printf("%s\n", list->str);
		list = list->next;
	}
	ft_printf("\n");
}
