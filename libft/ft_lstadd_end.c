/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:40:13 by jgilfix           #+#    #+#             */
/*   Updated: 2019/09/10 23:47:26 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	adds element `new` to the end of t_list* pointed to by
**					`alst`.
**
**	PARAMS:			1.	`alst` : pointer to pointer to beginning of list
**					2.	`new`  : element to add to the end of `alst`
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
