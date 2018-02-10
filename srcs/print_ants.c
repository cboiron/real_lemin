/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 22:04:15 by cboiron           #+#    #+#             */
/*   Updated: 2018/02/10 08:48:37 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	print_one_turn(int path_size, char **path, int *room)
{
	int index;

	index = 1;
	while (index < path_size)
	{
		if (room[index] > 0)
		{
			ft_putstr("L");
			ft_putnbr(room[index]);
			ft_putstr("-");
			ft_putstr(path[index]);
			ft_putstr(" ");
		}

		index++;
	}
	ft_putendl("");
}


void	increase_ants(int ants, char **path, int path_size)
{
	int room[path_size - 1];
	int i;
	int turn;
	int x;

	ft_putnbr(ants);
	ft_putendl("antsssssss");
	i = 1;
	turn = 1;
	while (i < path_size)
	{
		room[i] = 0;
		//ft_putnbr(room[i]);
		i++;
	}

	while (room[path_size - 1] != ants)
	{
		x = 0;
		// Parcours du tableau d'int
		while (x < path_size && room[path_size - 1] < ants)
		{
			//ft_putnbr(room[path_size-1]);
			//ft_putendl("nameeee");
			if (room[x] == ants)
			{
				room[x] = -1;
			}
		//	else
			else if (room[x] != -1 && x < turn)
			{
				room[x] += 1;
			}
			x++;
		}
		print_one_turn(path_size, path, room);
		i = 1;
		/*while (i < path_size)
		{
			if (room[i])
			ft_putnbr(room[i]);
			//ft_putendl("");
			i++;
		}*/
		ft_putendl("");
		turn++;
	}
}

int 	get_path_size(char **path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	return (i);
}

void	print_ants(int ants, char **path)
{
	int path_size;

	path_size = get_path_size(path);
	if (path_size >= 2)
		increase_ants(ants, path, path_size);
	else
		ft_putendl("No path");
}
