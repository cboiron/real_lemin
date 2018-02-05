/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:37:31 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/04 15:37:33 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lemin.h"

t_path	*new_path(t_room *room)
{
	t_path	*path;

	path = ft_memalloc(sizeof(t_path));
	path->next = NULL;
	return (path);
}

int		go_in_room(t_room *room, t_env *env, t_path *path)
{
	t_link	*link;
	//int		i;
	//i = -1;
	
	link = room->link;
	room->visited = 1;
	if (ft_strcmp(room->name, env->end->name) == 0)
	{
		ft_putendl(room->name);
		ft_putendl("exit found");
		//while(1)
		//	i++;
		return (1);
	}
	while (link)
	{
		if (link->node->visited != 1)
		{
			//ft_putstr("J'explore ");
			ft_putendl(link->node->name);
			add_path(&(path->start), link->node);
			go_in_room(link->node, env, path);
			//link->node->visited = 0;
		}
		link = link->next;
	}
	// }
	// else
	return (0);
}


/*
 * Verifie qu'il y ai un debut ET une fin ET des fourmis
 */

void	check_integrity(t_env *env)
{
	if (env->ants_nbr <= 0)
	{	
		ft_putendl("invalid number of ants");
		exit(0);
	}
	else if (!(env)->start || !(env)->end)
	{
		ft_putendl("starting or ending room is missing");
		exit(0);
	}
	//else if (!(env)->start-> == !(env)->end)
}

void	treat_data(t_env *env)
{
	t_path	*path;

	path = new_path(env->start);
	check_integrity(env);
	//count_links(env->start);
	//env->path->start = env->start;
	env->start->visited = 1;
	if (go_in_room(env->start, env, path) == 1)
		exit(1);
	//else
		//ft_putendl("no path");
}