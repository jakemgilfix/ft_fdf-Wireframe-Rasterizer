/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:34:35 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 21:22:17 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	count_digits(unsigned int n)
{
	unsigned char	digits;

	digits = 1;
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char					*ft_itoa(int n)
{
	unsigned char	digits;
	unsigned int	u_n;
	char			*result;

	if (!n)
		return (ft_strdup("0"));
	u_n = (unsigned int)((n < 0) ? -n : n);
	digits = count_digits(u_n);
	if (!(result = ft_strnew(digits + ((n < 0) ? 1 : 0))))
		return (0);
	result[0] = '-';
	if (n < 0)
		digits++;
	while (u_n)
	{
		result[--digits] = (u_n % 10) + '0';
		u_n /= 10;
	}
	return (result);
}
