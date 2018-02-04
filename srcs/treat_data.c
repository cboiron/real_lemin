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

void	go_in_room(t_room *room, t_env *env)
{
	t_room	*tmp;
	//int		i;

	//i = -1;
	tmp = room;
	ft_putchar('w');
	if (ft_strcmp(tmp->name, env->end->name) == 0)
	{
		//ft_putnbr(tmp->length);
		ft_putendl(tmp->name);
		ft_putendl("exit found");
		exit(1);
	}
	ft_putchar('e');
		//set_path();
	// if (tmp->visited == 0)
	// {
		//if (tmp)
			while (tmp->link)
			{
				ft_putendl("boucle");
				ft_putendl(tmp->link->node->name);
				if (tmp->link->node->visited == 1)
				{
					tmp = tmp->link->next->node;
					continue ;
				}
				ft_putstr("J'explore ");
				ft_putendl(tmp->link->node->name);
				tmp->link->node->visited = 1;
				/*
				if (ft_strcmp(tmp->link->node->name, env->end->name) == 0)
				{
					//ft_putnbr(tmp->length);
					ft_putendl(tmp->name);
					ft_putendl("exit found");
					exit(1);
				}
				*/
				//tmp->links_tab[i]->length += 1;
				//ft_putendl(tmp->link->node->name);
				go_in_room(tmp->link->node, env);
				tmp->link->node->visited = 0;
				//tmp->links_tab[i]->visited = 0;
				//tmp->links_tab[i]->length -= 1;
				
			}
	// }
	// else
	// 	return ;
}

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
	/*ft_putendl("count = ");
	ft_putnbr(count);
	ft_putendl("");*/
	return (count);
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
	check_integrity(env);
	//count_links(env->start);
	go_in_room(env->start, env);
}