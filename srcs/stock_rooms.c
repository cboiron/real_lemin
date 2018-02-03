/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:02:17 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/11 02:41:37 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		check_room_format(t_env *env, char **room)
{
	if (!room[0] || !room[1] || !room[2])
		return (-6);
	if (!ft_isalpha((int)room[0]) || !ft_isnum(room[1]) || !ft_isnum(room[2]))
		return (-7);
	if (room[0][0] == 'L')
		return (-8);
	//if (ft_atoi(room[1]) < INT_MIN || ft_atoi(room[2]) < INT_MIN ||
	//		ft_atoi(room[1]) > INT_MAX || ft_atoi(room[2]) > INT_MAX)
	//	return (0);
	return (1);
}

void	init_room(t_room *room)
{
	
}
int   	get_room(t_env *env, char **data, int room_spec)
//int   	stock_rooms(t_env *e, char *line, int spec)
{
	t_room	*new;

	new = NULL;
	if (!check_room_format((env), data))
		return (-9);
	new = ft_memalloc(sizeof(t_room));
	//init_room(new);
	//ft_putendl(data[0]);
	new->name = ft_strdup(data[0]);
	new->visited = 0;
	new->length = 0;
	new->link = NULL;
	new->next = NULL;
	if (room_spec == START)
		(env)->start = new;
	else if (room_spec == END)
		(env)->end = new;
	add_room(&(env->begin), new);
	return (1);
}

