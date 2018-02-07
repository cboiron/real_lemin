/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 05:51:23 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/02 05:53:28 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int	ft_is_not_num(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (!ft_isdigit(str[i]))
		return (0);
	}
	return (1);
}

int	ft_is_not_alphanum(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (!ft_isdigit(str[i]) || !ft_isalpha(str[i]))
		return (0);
	}
	return (1);
}

void	free_path(t_path *path)
{
	t_path	*tmp;

	tmp = (path);
	while (tmp)
	{
		ft_putendl("salut");
		tmp = tmp->next;
		free(&(path)->name);
		//free((path)->next);
		//free((path));
		path = tmp;
	}
}