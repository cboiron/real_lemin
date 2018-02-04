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
	t_room	*tmp;

	tmp = NULL;
	if (!room[0] || !room[1] || !room[2])
		return (-6);
	if (ft_is_not_alphanum(room[0]) || ft_is_not_num(room[1]) 
		|| ft_is_not_num(room[2]))
		return (-7);
	if (room[0][0] == 'L')
	{	
		ft_putendl("No 'L' at the start of a room name authorized");
			exit(0);
	}
	if (env->begin)
	{
		tmp = env->begin;	
		while (tmp)
		{
			if (ft_strcmp(tmp->name, room[0]) == 0)
			{
				ft_putendl("two different rooms can't have the same name");
				exit(0);
				return (-18);
			}
			tmp = tmp->next;
		}
		//ft_putendl("\n\n");
	}
	return (1);
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

