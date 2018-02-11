/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:57:43 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/10 09:18:45 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		free_split(char **split)
{
	if (split[0])
	{
		free(split[0]);
		if (split[1])
		{
			free(split[1]);
			if (split[2])
				free(split[2]);
		}
	}
}

int			norme(t_env *env, char **split_space, int room_spec)
{
	int		ret;

	ret = (get_room((env), split_space, room_spec));
	free_split(split_space);
	return (ret);
}

int			get_ants(t_env *env, char *nb_fourmi)
{
	int		nb;

	nb = 0;
	if ((env)->ants_nbr != -5)
		return (-1);
	nb = ft_atoi(nb_fourmi);
	if (nb > 0)
	{
		(env)->ants_nbr = nb;
		free(nb_fourmi);
		return (1);
	}
	return (-2);
}

int			analyse(t_env *env, char *line, int room_spec)
{
	char	**split_space;
	int		ret;

	ret = -4;
	split_space = ft_strsplit(line, ' ');
	if ((env)->ants_nbr == -5 && ft_strchr(line, '-') == NULL)
	{
		if (split_space[0] && !split_space[1])
			ret = (get_ants((env), split_space[0]));
	}
	else if (ft_strchr(line, '-') != NULL && (!(env)->start || !(env)->end)
		&& room_spec != 0)
		ret = -3;
	else if (ft_strchr(line, '-') != NULL)
	{
		ret = (get_tube((env), ft_strsplit(line, '-')));
		free(split_space[0]);
	}
	else if (split_space[0] && split_space[1] && split_space[2]
		&& (env)->ants_nbr != -5)
		ret = norme(env, split_space, room_spec);
	else if (is_comment(line))
		ret = (0);
	free(split_space);
	return (ret);
}

void		parse_rooms(t_env *env, char *line)
{
	int		room;

	room = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			break ;
		ft_putendl(line);
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line,
			"##end") == 0)
		{
			if (ft_strcmp(line, "##start") == 0)
				room = START;
			else
				room = END;
			free(line);
			continue ;
		}
		else if (is_comment(line))
		{
			free(line);
			continue ;
		}
		if (analyse(env, line, room) < -1)
			break ;
		room = 0;
		free(line);
	}
}
