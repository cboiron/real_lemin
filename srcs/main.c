/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:15:57 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/08 01:09:15 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		init_env(t_env *env)
{
	env->ants_nbr = -5;
	env->start = NULL;
	env->end = NULL;
	env->path = NULL;
	env->end_found = 0;
}

void		free_all(t_env *env)
{
	t_room	*tmp;

	tmp = env->begin;
	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

int			main(void)
{
	char	*line;
	t_env	*e;
	t_room	*r;
	t_link	*link;

	line = NULL;
	e = ft_memalloc(sizeof(t_env));
	init_env(e);
	parse_rooms(e, line);
	free(line);
	treat_data(e);
	return (0);
}
