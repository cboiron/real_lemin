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

t_path		*new_path(char *name)
{
	t_path	*path;

	path = ft_memalloc(sizeof(t_path));
	path->name = ft_strdup(name);
	path->next = NULL;
	return (path);
}

//Leaks dans ma recursive : Nom des salles qui composent le chemin

int			go_in_room(t_room *room, t_env **env, t_path **path)
{
	t_link	*link;
	t_path	*new_path;

	link = room->link;
	room->visited = 1;
	if (ft_strcmp(room->name, (*env)->end->name) == 0)
	{
		//ft_putendl(room->name);
		(*env)->end_found = 1;
		ft_putendl("exit found");
		return (1);
	}
	while (link)
	{
		if (link->node->visited != 1)
		{
			add_to_path(path, link->node->name);
			go_in_room(link->node, env, path);
			if ((*env)->end_found == 1)
				return (1);
				//ft_putendl("TATEWSGFDV");
			del_from_path(path);
			link->node->visited = 0;
		}
		//del_from_path(&(*path), link->node->name);
		link = link->next;
	}
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
}

void	treat_data(t_env *env)
{
	t_path	*path;
	t_path	*tmp;
	t_room	*room;

	//path = NULL;
	check_integrity(env);
	path = new_path(env->start->name);
	env->start->visited = 1;
	go_in_room(env->start, &env, &path);
	if (path)
	{
		tmp = path;
		while (tmp)
		{
		//ft_putendl("je passse");
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
		free_path(path);
	}
	else
		ft_putendl("no path");
	//sleep(100);
}