/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:41:56 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/11 02:45:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			norme(t_env *env, char **split_space, int room_spec)
{
	int		ret;

	ret = (get_room((env), split_space, room_spec));
	free_split(split_space);
	return (ret);
}

void		norme_2(char *line, int *room)
{
	if (ft_strcmp(line, "##start") == 0)
		*room = START;
	else
		*room = END;
	free(line);
}

int			norme_3(t_env *env, char *line, char **split_space)
{
	int		ret;

	ret = (get_tube((env), ft_strsplit(line, '-')));
	free(split_space[0]);
	return (ret);
}
