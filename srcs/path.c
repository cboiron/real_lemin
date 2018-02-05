/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 04:17:46 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/01 03:58:17 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

//.   CA BUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
//		SEGFAULT
/*
t_room		**fill_tab(t_env *e, t_link *link)
{
	int		nb_links;
	int		i;
	t_room	**tab;

	i = 0;
	tab = NULL;
	nb_links = count_links(link);
	ft_putendl("debut");
	//tab = (t_room **)malloc(sizeof(t_room *) * ((nb_links) + 1));
	tab = ft_memalloc(sizeof(t_room *) * ((nb_links) + 1));
	ft_putnbr(sizeof(tab));
	if (!tab)
	{
		ft_putendl("FAILLLLLLLLL");
		exit (0);
	}
	ft_putendl("milieu");
	tab[nb_links] = NULL;
	while (link)
	{
		tab[i] = link->node;
		link = link->next;
		i++;
	}
	ft_putendl("fin");
	return (tab);
}

t_room		**links_in_tab(t_env *e, char *room_name)
{
	t_room	*room;
	t_link	*link;
	t_room	**tab;

	tab = NULL;
	link = NULL;
	room = e->r;
	
	while (ft_strcmp(room->name, room_name) != 0)
		room = room->next;
	link = room->link;
	ft_putstr("-------------------");
	ft_putendl("Room name ->   ");
	ft_putstr(room_name);
	ft_putendl("");
	tab = fill_tab(e, link);
	return (tab);
	if (link)
	{
	ft_putstr("Salle = ");
	ft_putendl(room->name);
	ft_putnbr(count_links(link));
	ft_putendl("  lien(s)");
	}
	else
	{
	ft_putstr("Salle = ");
	ft_putendl(room->name);
	ft_putendl("0 lien(s)");
	}
	
}

void		find_paths(t_env *e)
{
	t_room	*tmp;
	t_link	*link;
	t_room	**links_tab;
	int		i;

	links_tab = NULL;
	link = NULL;
	tmp = e->r;
	check_data(e);
	while (tmp)
	{
		//ft_putendl(tmp->name);
		tmp->links_tab = links_in_tab(e, tmp->name);
		i = 0;
		ft_putstr("Nom de la salle : ");
		ft_putendl(tmp->name);
		ft_putstr("Liens : ");
		while (tmp->links_tab[i])
			{
				ft_putendl(tmp->links_tab[i]->name);
				i++;
			}
		tmp = tmp->next;
	}
	starting(e);
	ft_putendl("bitch");
}
*/