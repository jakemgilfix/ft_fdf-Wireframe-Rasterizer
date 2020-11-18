/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:13:31 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/14 20:15:33 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	takes as a parameter the address of a string that needs to
**					freed, then sets its pointer to NULL.
**
**	PARAMS:			1.	`as` : address of string
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	free()
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
