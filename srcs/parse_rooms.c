/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:57:43 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/11 04:12:50 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int	is_comment(char *line)
{
	if (line[0] == '#')
		return (2);
	return (0);
}

int get_ants(t_env *env, char *nb_fourmi)
{
	int nb;

	nb = 0;
	if  ((env)->ants_nbr != -5)
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

int analyse(t_env *env, char *line,  int room_spec)
{
	char	**split_space;
	int 	ret;

	ret = -4;
	split_space = ft_strsplit(line, ' ');
	if ((env)->ants_nbr == -5  && ft_strchr(line, '-') == NULL)
	{
		if (split_space[0] && !split_space[1])
		{
			ret =(get_ants((env), split_space[0]));
		}
	}
	else if (ft_strchr(line, '-') != NULL && (!(env)->start || !(env)->end)
		&& room_spec != 0)
	{
		ret = -3;
	}
	else if (ft_strchr(line, '-') != NULL)
	{
		//ft_putendl("c'est un tube");
		ret = (get_tube((env), ft_strsplit(line, '-')));
		free(split_space[0]);
	}
	else if (split_space[0] && split_space[1] && split_space[2])
	{
		//ft_putendl("c'est une salle");
		ret = (get_room((env), split_space, room_spec));
		free(split_space[0]);
		free(split_space[1]);
		free(split_space[2]);
	}
	else if (is_comment(line))
		ret = (0);
	
	free(split_space);
	return (ret);
}
/*
 *Nom de salle vide ou contenant un '-' : erreur
 */

void	parse_rooms(t_env *env, char *line)
{
	int	room;

	room = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			break ;
		//ft_putendl(line);
		if (ft_strcmp(line, "##start") == 0)
		{
			room = START;
			free(line);
			continue ;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			room = END;
			free(line);
			continue ;
		}
		else if (is_comment(line))
			continue ;
		if (analyse(env, line, room) < -1)
			break;
		//printf("retour = %d\n",analyse(env, line, room));
		room = 0;
		free(line);
	}
	free(line);
}