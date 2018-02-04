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
	ft_putendl("count = ");
	ft_putnbr(count);
	ft_putendl("");
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
	count_links(env->start);
}