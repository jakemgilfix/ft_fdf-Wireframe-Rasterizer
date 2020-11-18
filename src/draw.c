/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:31:33 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 14:16:15 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

/*
** FILL_IMAGE ******************************************************************
**   ~ Fills image (the result of mlx_get_data_addr()) of given dimensions    **
**     with pixels of the given color.                                        **
********************************************************************************
*/

void			fill_image(int *img, size_t height, size_t width, int color)
{
	size_t	i;

	i = height * width;
	while (i--)
		img[i] = color;
}

/*
** CREATE_POINT ****************************************************************
**   ~ Returns a `t_point` structure with the given `x` and `y` values,       **
**     fetching the z-coordinate from `fdf->map->z_coords` and assigning it   **
**     to both the `z` and `color` fields of the returned structure.          **
**     Used exclusively by the `draw()` function.                             **
********************************************************************************
*/

static t_point	create_point(int x, int y, t_map *map)
{
	return ((t_point){x, y, map->z_coords[y * map->width + x],
		map->z_coords[y * map->width + x]});
}

/*
** DRAW ************************************************************************
**   ~ Draws the given map in the main window. First, fills the window with   **
**     the background color defined in "fdf.h", then reads through the map,   **
**     projecting the 3-D coordinates onto the 2-D plane and drawing lines    **
**     between adjacent points. The viewing angle is saved in a `t_camera`    **
**     struct contained in `fdf`.                                             **
********************************************************************************
*/

void			draw(t_fdf *fdf)
{
	int	x;
	int	y;

	fill_image(fdf->main_data, MAIN_H, MAIN_W, MAIN_COLOR);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->main_img, SB_W, 0);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x < (fdf->map->width - 1))
				draw_line(project(create_point(x, y, fdf->map), fdf),
					project(create_point(x + 1, y, fdf->map), fdf), fdf);
			if (y < (fdf->map->height - 1))
				draw_line(project(create_point(x, y, fdf->map), fdf),
					project(create_point(x, y + 1, fdf->map), fdf), fdf);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->main_img, SB_W, 0);
}
