/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:15:57 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/11 02:03:02 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		init_env(t_env *env)
{
	env->ants_nbr = -5;
	env->start = NULL;
	env->end = NULL;
	env->path = NULL;
	env->end_found = 0;
}

void		free_all(t_env *env)
{
	t_room	*tmp;
	t_room	*room;
	t_link	*tmp_link;
	t_link	*link;

	room = env->begin;
	tmp = NULL;
	while (room)
	{
		tmp = room->next;
		link = room->link;
		while (link)
		{
			tmp_link = link->next;
			free(link);
			link = tmp_link;
		}
		free(room->name);
		free(room);
		room = tmp;
	}
}

int			main(void)
{
	char	*line;
	t_env	*e;

	line = NULL;
	e = ft_memalloc(sizeof(t_env));
	init_env(e);
	parse_rooms(e, line);
	treat_data(e);
	free_all(e);
	free(e);
	return (0);
}
