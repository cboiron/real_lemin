/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 04:56:47 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/08 04:56:50 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			get_path_length(t_path *list_path)
{
	t_path	*tmp;
	int		count;

	count = 0;
	tmp = list_path;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char		**list_to_array(t_path *list_path)
{
	t_path	*tmp;
	int		length;
	char	**path;

	tmp = list_path;
	length = get_path_length(list_path);
	path = ft_memalloc(sizeof(char*) * (length));
	path[length] = NULL;
	while (tmp)
	{
		path[length - 1] = ft_strdup(tmp->name);
		tmp = tmp->next;
		length--;
	}
	return (path);
}

void		free_array(char **path)
{
	int		index;

	index = 0;
	while (path[index])
	{
		free(path[index]);
		index++;
	}
	free(path);
}

void		process(t_env *env, t_path *list_path)
{
	char	**path;
	int		index;

	index = 0;
	path = list_to_array(list_path);
	while (path[index])
	{
		ft_putendl(path[index]);
		index++;
	}
	free_array(path);
}
