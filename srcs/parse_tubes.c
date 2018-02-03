/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 23:10:41 by cboiron           #+#    #+#             */
/*   Updated: 2017/12/11 00:20:24 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"
/*
void	parse_tubes(t_env *e, char *line)
{
	if (!line || ft_strchr(line, '-') == NULL)
		return ;
	//ft_putendl(line);
	stock_tubes(e, line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		//ft_putendl(line);
		if (!line)
		{
			ft_putendl("end of reading");
			return ;
		}
		else if (ft_strchr(line, '-') == NULL)
		{
			ft_strdel(&line);
			break ;
		}
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_strdel(&line);
		else
			get_tubes(e, line);
		ft_strdel(&line);
	}
}*/