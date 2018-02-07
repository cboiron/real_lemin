/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:17:55 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/11 05:39:51 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

# include <stdio.h>

# define START 50
# define END 60

typedef struct s_path
{
	char 		*name;
	struct 		s_path *next;
}				t_path;

typedef struct	s_link
{
	struct  	s_room *node;
	struct		s_link *next;
}				t_link;

typedef struct	s_room
{
	char		*name;
	int			visited;
	struct 		s_link *link;
	struct		s_room *next;
	}			t_room;

typedef struct	s_env
{
	int			ants_nbr;
	int 		end_found;
	struct 		s_path *path;
	struct 		s_room *start;
	struct 		s_room *end;
	struct   	s_room *begin;
}				t_env;

void	parse_rooms(t_env *env, char *line);
int 	ft_is_not_num(char *s);
int		ft_is_not_alphanum(char *str);
int   	get_room(t_env *env, char **data, int room_spec);
void	treat_data(t_env *e);
void	add_room(t_room **lst, t_room *new_room);
void	add_link(t_link **lst, t_link *new_link);
void	add_to_path(t_path **path, char *name);
void	del_from_path(t_path **path, char *name);
void	free_path(t_path *path);
t_path	*new_path(char *name);

t_room	**links_in_tab(t_env *e, char *room_name);
int		get_start_end(t_env *env, char **cmd);
int		get_tube(t_env *env, char **tube);
int		analyse_line(t_env *env, char *line);
long	nb_fourmi(char *line);
void	del_lst(t_env **env);
void	parse_tubes(t_env *env, char *line);
void	stock_tubes(t_env *env, char *tube);
void	find_paths(t_env *env);
void	starting(t_env *e);
void	error();
t_room	*stock_rooms(t_env *e, char *line, int spec);

void	print_links(t_env *e);

#endif