/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:25:37 by cboiron           #+#    #+#             */
/*   Updated: 2018/01/30 18:25:51 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"
/*
void	set_path()
{

}

void	go_in_room(t_room *room, t_env *e)
{
	t_room	*tmp;
	int		i;

	i = -1;
	tmp = room;
	if (tmp->end == 1)
	{
		ft_putnbr(tmp->length);
		ft_putendl(tmp->name);
		ft_putendl("exit found");
		exit(1);
	}
		//set_path();
	// if (tmp->visited == 0)
	// {
		if (tmp->links_tab)
			while (tmp->links_tab[++i])
			{
				if (tmp->links_tab[i]->visited == 1)
					continue ;
				ft_putstr("J'explore ");
				ft_putendl(tmp->links_tab[i]->name);
				tmp->links_tab[i]->visited = 1;
				tmp->links_tab[i]->length += 1;
				go_in_room(tmp->links_tab[i], e);
				tmp->links_tab[i]->visited = 0;
				tmp->links_tab[i]->length -= 1;
				// i++;
			}
	// }
	// else
	// 	return ;
}


 * On se place dans la salle de depart
 

void	starting(t_env *e)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = e->r;
	while (ft_strcmp(tmp->name, e->start) != 0)
		tmp = tmp->next;
	// tmp->visited = 1;
	if (tmp)
		go_in_room(tmp, e);
}
*/