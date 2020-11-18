/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:55:01 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 11:57:53 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "fdf.h"

/*
** DRAW_MENU *******************************************************************
**   ~ Draws the sidebar menu. Menu options are set in "menu.h". The array    **
**     items[] lists all the menu items to be displayed.                      **
********************************************************************************
*/

void	draw_menu(t_fdf *fdf)
{
	const char	*items[] = {"[ARROWS] Translate", "[MWHEEL] Zoom",
		"[MOUSE1] Rotate", "[I]      Isometric View",
		"[P]      Parallel View", "[ESC]    Quit"};
	int			i;

	mlx_string_put(fdf->mlx, fdf->win, POS_X, POS_Y, H_COLOR, HEADING);
	i = 0;
	while (i++ < (int)(sizeof(items) / sizeof(*items)))
		mlx_string_put(fdf->mlx, fdf->win, POS_X, POS_Y + i * V_SPC, ITEM_COLOR,
			(char *)(items[i - 1]));
}
