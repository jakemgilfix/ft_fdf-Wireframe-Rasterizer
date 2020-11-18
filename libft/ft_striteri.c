/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:21:45 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:13:37 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	applies the function `f` to each character of the string
**					passed as argument, passing the index as a first argument
**					to `f`. Each character is passed by address to `f` to be
**					modified if necessary.
**
**	PARAMS:			1.	`s` : string to apply `f` to
**					2.	`f` : function to apply to string `s`
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && *s && f)
		while (s[i++])
			f(i - 1, &s[i - 1]);
}
