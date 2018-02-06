/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:29:32 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/05 05:56:38 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	add_room(t_room **lst, t_room *new_room)
{
	if (*lst)
		new_room->next = *lst;
	*lst = new_room;
}

void	add_link(t_link **lst, t_link *new_link)
{
	if (*lst)
		new_link->next = *lst;
	*lst = new_link;
}

void	add_to_path(t_path **path, char *name)
{
	t_path	*tmp;

	//ft_putendl(name);
	tmp = new_path(name);
	if (*path)
		tmp->next = *path;
	*path = tmp;
}

void	del_from_path(t_path **path, char *name)
{
	t_path 	*tmp;

	tmp = *path;
	*path = (*path)->next;
	free(tmp);
	//ft_putendl("je free : ");
	//ft_putendl((*path)->name);
	//ft_putendl("dans name: ");
	//ft_putendl(name);
//	free(path);
//	*path = tmp;
}