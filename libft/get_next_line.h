/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:24:30 by cboiron           #+#    #+#             */
/*   Updated: 2017/06/20 16:35:41 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

int	get_next_line(const int fd, char **line);

#endif
