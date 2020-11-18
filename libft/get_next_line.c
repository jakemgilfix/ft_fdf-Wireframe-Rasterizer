/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:10:01 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:56:43 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

/*
******************************* HOW THIS WORKS: *******************************
** If any one of:
**		a) The file descriptor is invalid
**		b) ln[fd] is NULL and ft_strnew(1) somehow returned NULL
**		c) line is NULL
**	Return -1
** Otherwise, while ln[fd] does NOT contain a '\n' AND read() successfully
**  read more than 0 bytes:
**		Null-terminate the buffer
**		Set temp = ln[fd]
**		Append what you read into the buffer to the end of ln[fd]
**		Free temp and set it to NULL
** If read() encountered an error, return -1
** Set temp = ln[fd]
** If temp is an empty string (i.e., temp[0] = '\0'), return 0 (You hit EOF)
** If ln[fd] contains a '\n':
**	Remove everything past the '\n' setting *line equal to the appropriate
**   substring of ln[fd]
** Otherwise, set *line = strdup(ln[fd])
** Set ln[fd] equal to the substring of ln[fd] containing anything past what is
**  now in *line
** Free temp and set it to NULL
*/

int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*ln[MAX_FD];
	char		*temp;
	ssize_t		bts;
	char		end;

	if ((fd < 0) || (!ln[fd] && !(ln[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!CHR(ln[fd], '\n') && (bts = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bts] = 0;
		temp = ln[fd];
		ln[fd] = ft_strjoin(ln[fd], buffer);
		ft_strdel(&temp);
	}
	if (bts == -1)
		return (-1);
	if (!*(temp = ln[fd]))
		return (0);
	end = CHR(ln[fd], '\n') ? 1 : 0;
	*line = end ? SUB(ln[fd], 0, CHR(ln[fd], '\n') - ln[fd]) : DUP(ln[fd]);
	ln[fd] = SUB(ln[fd], LEN(*line) + end, LEN(ln[fd]) - LEN(*line) + end);
	ft_strdel(&temp);
	return (ln[fd] || LEN(*line));
}
