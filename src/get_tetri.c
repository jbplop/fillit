/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:35:31 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/03 18:39:13 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetri.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void	free_tmp(int index, char **tmp)
{
	while (--index >= 0)
	{
		free(tmp[index]);
		tmp[index] = NULL;
	}
	free(tmp);
	tmp = NULL;
}

char		**get_tetri(int fd)
{
	int		index;
	char	line[5];
	char	**tmp;
	static int i = 0;

	index = 0;
	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	ft_bzero(tmp, sizeof(char *) * 4);
	while (index < 4 && read(fd, line, 5))
	{
		if (line[4] != '\n')
		{
			free_tmp(index, tmp);
			return (NULL);
		}
		tmp[index] = ft_strndup(line, 4);
		index++;
	}
	if (index != 4)
	{
		free_tmp(index, tmp);
		return (NULL);
	}
	ft_putendl("CC");
	while(i == 2);
	i++;
	return (tmp);
}
