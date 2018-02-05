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

int		go_in_room(t_room *room, t_env *env)
{
	t_link	*link;
	int		i;
	i = -1;
	
	link = room->link;
	room->visited = 1;
	if (ft_strcmp(room->name, env->end->name) == 0)
	{
		//ft_putnbr(tmp->length);
		ft_putendl(room->name);
		ft_putendl("exit found");
		while(1)
			i++;
		exit(1);
		//return (1);
		//exit(1);
	}
	while (link)
	{
		if (link->node->visited != 1)
		{
			//ft_putstr("J'explore ");
			//ft_putendl(link->node->name);
			go_in_room(link->node, env);
			link->node->visited = 0;
		}
		link = link->next;
	}
	// }
	// else
	return (0);
}

/*
int			count_links(t_room *room)
{
	t_link	*link;
	int		count;

	link = room->link;
	count = 0;
	while (link)
	{
		ft_putendl(link->node->name);
		link = link->next;
		count++;
	}
	return (count);
}
*/

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
	check_integrity(env);
	//count_links(env->start);
	env->start->visited = 1;
	if (go_in_room(env->start, env) == 1)
		exit(1);
	else
		ft_putendl("no path");
}