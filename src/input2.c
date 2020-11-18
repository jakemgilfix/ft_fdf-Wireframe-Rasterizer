/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:11:16 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 11:53:32 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** LST_TO_ARR ******************************************************************
**   ~ Takes a list of lines read from the input file (`head`) and parses     **
**     them, storing the given coordinates in a (1-D, integer) coordinate     **
**     array.                                                                 **
********************************************************************************
*/

void				lst_to_arr(t_list *head, t_map *map)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	while (head)
	{
		line = ft_split((char *)head->content, " ");
		j = -1;
		while (line[++j])
		{
			map->z_coords[i++] = ft_atoi(line[j]);
			free(line[j]);
		}
		free(line);
		head = head->next;
	}
}
