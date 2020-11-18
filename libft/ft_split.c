/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:03:44 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/28 23:30:06 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	Allocates and returns an array of "fresh" strings (ending
**					w/ '\0') obtained by splitting the string `str` using the
**					characters contained within `separators` as delimiters. If
**					the allocation fails, the function returns NULL.
**
**	PARAMS:			1.	`str`        : string to split
**					2.  `separators` : string containing "delimiter" characters
**
**	RETURN VALUE:	Returns list of "words" in `str`
**
**	LIBC FUNCTIONS:	malloc(), free()[?]
*/

static unsigned int		word_count(char const *str, char const *separators)
{
	unsigned int	wc;

	wc = 0;
	while (*str)
	{
		while (*str && ft_strchr(separators, *str))
			str++;
		wc += (*str) ? 1 : 0;
		while (*str && !ft_strchr(separators, *str))
			str++;
	}
	return (wc);
}

static void				ft_split_cpy(char **result, char const *str,
		char const *separators)
{
	unsigned int	word_index;
	unsigned int	word_size;

	word_index = 0;
	while (*str)
	{
		while (*str && ft_strchr(separators, *str))
			str++;
		if (!(*str))
			break ;
		word_size = 0;
		while (*str && !ft_strchr(separators, *str))
		{
			str++;
			word_size++;
		}
		result[word_index] = ft_strnew(word_size);
		(void)ft_strncpy(result[word_index++], str - word_size, word_size);
	}
}

char					**ft_split(char const *str, char const *separators)
{
	char	**result;
	int		wc;

	if (!str || !separators)
	{
		ft_error(ERROR_NULL_PTR);
		return (NULL);
	}
	wc = word_count(str, separators);
	if (!(result = (char **)malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	result[wc] = NULL;
	ft_split_cpy(result, str, separators);
	return (result);
}
