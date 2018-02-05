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

void	add_path(t_room **path, t_room *new_room)
{
	if (*path)
		new_room->next = *path;
	*path = new_room;
}