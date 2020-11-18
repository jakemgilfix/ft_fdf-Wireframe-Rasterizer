/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:18:13 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 21:26:02 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	applies the function `f` to each character of the string
**					passed as argument. Each character is passed by address to
**					`f` to be modified if necessary.
**
**	PARAMS:			1.	`s` : string to apply `f` to
**					2.	`f` : function to apply to string `s`
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
