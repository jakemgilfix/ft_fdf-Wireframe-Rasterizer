/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:53:18 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 14:35:00 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** FREE_LINE *******************************************************************
**   ~ Free()s the given line.                                                **
********************************************************************************
*/

static void			free_line(void *line, size_t line_len)
{
	(void)line_len;
	ft_memdel(&line);
}

/*
** LINE_LEN ********************************************************************
**   ~ Calculates the length of the given map line and returns it (or 0 if it **
**     doesn't match the length of previously read lines). Also updates the   **
**     minimum and maximum z-coordinates saved in `map`.                      **
********************************************************************************
*/

static int			line_len(void *line, t_map *map)
{
	int		len;
	char	**split;

	len = -1;
	split = ft_split((char *)line, " ");
	while (split[++len])
	{
		map->z_max = ft_int_max(map->z_max, ft_atoi(split[len]));
		map->z_min = ft_int_min(map->z_min, ft_atoi(split[len]));
		free(split[len]);
	}
	free(split);
	return ((!map->width || (map->width == len)) ? len : 0);
}

/*
** VALID_LINE ******************************************************************
**   ~ Returns TRUE if the line contains only digits, whitespace, and '-'.    **
**     Otherwise, returns FALSE.                                              **
********************************************************************************
*/

static t_boolean	valid_line(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line) && !ft_iswhitespace(*line) && (*line != '-'))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

/*
** VALIDATE_LINES **************************************************************
**   ~ Returns TRUE if the list of read map lines given in `head` contains    **
**     a positive number of valid lines, each of the same length. Otherwise,  **
**     returns FALSE.                                                         **
********************************************************************************
*/

static t_boolean	validate_lines(t_map *map, t_list *head)
{
	if (!map || !head)
		return (FALSE);
	while (head)
	{
		if (!valid_line((char *)head->content))
			return (FALSE);
		map->height++;
		map->width = line_len(head->content, map);
		head = head->next;
	}
	return ((map->height && map->width) ? TRUE : FALSE);
}

/*
** READ_MAP ********************************************************************
**   ~ Reads the file (using get_next_line()) given as argument to the        **
**     program into a linked list of lines, validates these lines, and stores **
**     the coordinates given in the file into a (1-D, integer) coordinate     **
**     array. Returns TRUE if the given file contained a valid map or FALSE   **
**     otherwise.                                                             **
********************************************************************************
*/

t_boolean			read_map(t_map *map, int fd)
{
	int		ret;
	char	*line;
	t_list	*ln_lst_head;

	ln_lst_head = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_lstadd_end(&ln_lst_head, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	ret = (int)validate_lines(map, ln_lst_head);
	if (ret)
	{
		map->z_coords = malloc(map->height * map->width * sizeof(int));
		lst_to_arr(ln_lst_head, map);
	}
	ft_lstdel(&ln_lst_head, free_line);
	return ((t_boolean)ret);
}
