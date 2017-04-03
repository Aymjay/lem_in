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

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct			s_lem_list
{
	char				*str;
	struct s_lem_list	*next;
}						t_lem_list;

typedef	struct			s_graff
{
	char				*name;
	int					count;
	int					data;
	int					weigth;
	int					w;
	struct s_graff		**next;
}						t_graff;

char					**parsing_rooms(t_lem_list **list, char *cmd);
char					**parsing_tubes(char **tab_rooms, t_lem_list **list);
t_lem_list				*lem_new_list(const char *line);
void					new_to_list(const char *line, t_lem_list **list);
void					all_to_list(char **line, t_lem_list **list);

int						list_func(t_lem_list *list, int f(char *str));
int						list_func_tube(t_lem_list *list,\
						char **tab, int f(char *str, char **tab));
int						isroom(char *line);

void					create_struc(t_graff **begin, t_graff **ending, \
						char **tab_rooms, char ***tab_tubes);
int						ending_modif(t_graff **begin, char *str, \
						t_graff **looking_for, int j);

void					changing_tab(char ***tab_rooms);

int						check_first(char *str, char *src, char **line);
int						check_scnd_struc(char *str, char *src, char **line);

int						resolve(t_graff **begin, int nb);
int						best(t_graff *ending, int nb, t_graff ****tab);
int						sending_ant(t_graff ****tab, \
						int ant, int ending, int *i);
int						walking(t_graff ****tab, int i, int ant, int j);
void					erraz(t_lem_list **list);
int						tube_count(char *str, char **tab_tubes);
void					print_all(t_lem_list *list);

void					free_tab(char ***tab);

int						resolve_w(t_graff **begin, t_graff *ending, int nb);
int						other_way(t_graff *ending, int nb, \
						t_graff ****tab, int j);
void					display_tab(t_graff ***tab, char *cmd,\
						t_graff *ending);
int						starting(char **tab_rooms, char **tab_tubes,\
						char *cmd, t_lem_list *l_begin);
int						checking_for_same(char **tab, int number, char *str);
int						ending_modif(t_graff **begin, char *str,\
						t_graff **looking_for, int j);
int						all_check(t_graff **begin, char *str,\
						t_graff **looking_for, int j);
#endif
