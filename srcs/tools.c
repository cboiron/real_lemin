/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 05:51:23 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/08 01:37:01 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		error(int nb)
{
	if (nb == -7)
	{
		ft_putendl("Wrong room format");
		exit(0);
	}
	else if (nb == -8)
	{
		ft_putendl("No 'L' at the start of a room name authorized");
		exit(0);
	}
	else if (nb == -9)
	{
		ft_putendl("Two different rooms can't have the same name");
		exit(0);
	}
}

int			is_comment(char *line)
{
	if (line[0] == '#')
		return (2);
	return (0);
}

int			ft_is_not_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_not_alphanum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || !ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		free_path(t_path *path)
{
	t_path	*tmp;

	tmp = path;
	while (tmp)
	{
		tmp = tmp->next;
		free(&(path)->name);
		free(path->name);
		path = tmp;
	}
}
