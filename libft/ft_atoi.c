/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:06:03 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:21:22 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	converts the initial portion of the string pointed to by
**					`str` to integer representation.
**
**	PARAMS:			1.	`str` : string to convert to integer
**
**	RETURN VALUE:	returns the integer representation of the string `str`
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	sign = 1;
	result = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = (*str++ == '-') ? -1 : 1;
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10 + *str++ - '0';
		if (result > (unsigned long long)LONG_MAX)
			return ((sign == 1) ? -1 : 0);
	}
	return ((int)(sign * result));
}
