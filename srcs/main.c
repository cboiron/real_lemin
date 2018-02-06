/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:15:57 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/11 03:16:51 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	init_env(t_env *env)
{
	env->ants_nbr = -5;
	env->start = NULL;
	env->end = NULL;
	env->path = NULL;
	env->end_found = 0;
}

void	free_all(t_env *env)
{
	t_room	*tmp;

	tmp = env->begin;
	//free(env->start);
	//free(env->end);
	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
		//env->begin = tmp;
	}
	//free(env->begin);
}

int	main()
{
	char	*line;
	t_env	*e;
	t_room 	*r;
	t_link	*link;

	line = NULL;
	e = ft_memalloc(sizeof(t_env));
	init_env(e);
	//ft_putnbr(e->ants_nbr);
	parse_rooms(e, line);
	treat_data(e);
	//ft_putendl(e->start->name);
	//ft_putendl(e->end->name);
	//sleep(15);
	return (0);
}

	/*
	------PARCOURS DES LIENS D'UNE SALLE---
	link = e->begin->link;
	while (link)
	{
	ft_putendl("liens :");
	ft_putendl(link->node->name);
	link = link->next;
	}
	---------------------------------------
	*/

	/*
	---------PARCOURS DE SALLES------------

	r = e->begin;
	while (r)
	{
		ft_putendl(r->name);
		r = r->next;
	}
	---------------------------------------
	*/


	/*
	ft_putstr("start = ");
	ft_putendl(e->start->name);
	ft_putstr("end = ");
	ft_putendl(e->end->name);
	*/
	//free_all(e);
	//while (1)
	//	i++;
