/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:43:36 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/11 02:10:32 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_link		*new_link(t_env *e, t_room *room)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		exit(0);
	link->node = room;

	return (link);
}
/*
void		save_link(t_env *e, char *room1, char *room2)
{
	t_room	*tmp;
	t_room	*ptr1;
	t_room	*ptr2;

	tmp = e->r;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, room1) == 0)
			ptr1 = tmp;
		else if (ft_strcmp(tmp->name, room2) == 0)
			ptr2 = tmp;
		tmp = tmp->next;
	}
	tmp = e->r;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, room2) == 0)
			add_link(&ptr1->link, new_link(e, ptr2));
		else if (ft_strcmp(tmp->name, room1) == 0)
			add_link(&ptr2->link, new_link(e, ptr1));
		tmp = tmp->next;
	}
}*/
/*
int			check_names(t_env *e, char *room1, char *room2)
{
	t_room	*tmp;
	int		match1;
	int		match2;

	match1 = 0;
	match2 = 0;
	tmp = e->r;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, room1) == 0)
			match1++;
		else if (ft_strcmp(tmp->name, room2) == 0)
			match2++;
		tmp = tmp->next;
	}
	if (match1 == 1 && match2 == 1)
	{
		//ft_putendl("rooms ok");
		//save_link(e, room1, room2);
		return (1);
	}
	else
		//ft_putendl("rooms not ok");
	return (0);
}*/
/*
void		get_tubes(t_env *e, char **tube)
{
	char*	room1;
	char*	room2;

	if (tube && tube[0] && tube[1])
	room1 = tube[0];
	room2 = tube[1];
	//check_names(e, room1, room2);
	free(tube[0]);
	free(tube[1]);
	free(tube);
}*/