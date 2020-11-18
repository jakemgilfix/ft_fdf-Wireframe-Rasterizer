/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:08:56 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:55:41 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef _UNISTD_H_
#  include <unistd.h>
# endif

# define BUFF_SIZE	69
# define MAX_FD		2147483647

# define SUB		ft_strsub
# define LEN		ft_strlen
# define DUP		ft_strdup
# define CHR		ft_strchr

int	get_next_line(const int fd, char **line);
#endif
