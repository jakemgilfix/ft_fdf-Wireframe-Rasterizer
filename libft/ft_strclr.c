/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:15:41 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:11:10 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	sets every character of the string `s` to '\0'
**
**	PARAMS:			1.	`s` : string to clear
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
