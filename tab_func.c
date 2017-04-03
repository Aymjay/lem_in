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

void	display_tab(t_graff ***tab, char *cmd, t_graff *ending)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i][0] && tab[i][1])
	{
		ft_printf("chemin %d = ", i + 1);
		while (tab[i][j] != ending)
		{
			ft_printf("%s ", tab[i][j]->name);
			++j;
		}
		ft_printf("%s ", tab[i][j]->name);
		j = 0;
		++i;
		ft_printf("\n");
		if (ft_strcmp(cmd, "-b") == 0)
			break ;
	}
	ft_printf("\n");
}

void	changing_tab(char ***tab_rooms)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*tab_rooms)[i])
	{
		str = malloc(ft_strlen((*tab_rooms)[i] - 3) * sizeof(char));
		while ((*tab_rooms)[i][j] != ' ')
		{
			str[j] = (*tab_rooms)[i][j];
			++j;
		}
		str[j] = '\0';
		j = 0;
		free((*tab_rooms)[i]);
		(*tab_rooms)[i] = ft_strdup(str);
		free(str);
		++i;
	}
}

void	free_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		++i;
	}
	free(*tab);
}
