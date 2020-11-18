/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:02:32 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 11:28:51 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** FT_PUTPIXEL *****************************************************************
**   ~ Puts a single pixel of the given color in the main window at           **
**     coordinates (x, y).                                                    **
**     Used exclusively by `draw_line()`                                      **
********************************************************************************
*/

static void	ft_putpixel(t_fdf *fdf, int x, int y, int color)
{
	if ((x >= 0) && (x < MAIN_W) && (y >= 0) && (y < MAIN_H))
		fdf->main_data[x + y * MAIN_W] = color;
}

/*
** COLOR_INTERP ****************************************************************
**   ~ Interpolates color (each RGB channel is considered seperately) based   **
**     on relative height of z-coordinate, given two "endpoint" colors.       **
**     Used exclusively by the `color()` function.                            **
********************************************************************************
*/

static int	color_interp(int start_color, int end_color, float percent)
{
	const int	rgb_start[3] = {(start_color >> 16) & 0xff,
		(start_color >> 8) & 0xff, start_color & 0xff};
	const int	rgb_end[3] = {(end_color >> 16) & 0xff, (end_color >> 8) & 0xff,
		end_color & 0xff};
	int			rgb[3];
	int			i;

	i = -1;
	while (++i < 3)
		rgb[i] = rgb_start[i] + percent * (rgb_end[i] - rgb_start[i]);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

/*
** COLOR ***********************************************************************
**   ~ Given a point between `start` and `end`, uses linear interpolation to  **
**     assign a color, based on relative height (z-coordinate) of `pt`.       **
**     Used exclusively by the `draw_line()` function.                        **
********************************************************************************
*/

static int	color(t_point pt, t_point start, t_point end, t_fdf *fdf)
{
	t_point	s;
	t_point	e;
	float	percent;
	float	z;

	if (fdf->map->z_min == fdf->map->z_max)
		return (COLOR0);
	if (start.x != end.x)
	{
		s = (start.x < end.x) ? start : end;
		e = (start.x < end.x) ? end : start;
		percent = (float)(pt.x - s.x) / (float)(e.x - s.x);
	}
	else
	{
		s = (start.y < end.y) ? start : end;
		e = (start.y < end.y) ? end : start;
		percent = (float)(pt.y - s.y) / (float)(e.y - s.y);
	}
	z = (s.color < e.color) ? s.color + percent * (e.color - s.color) :
		e.color + (1 - percent) * (s.color - e.color);
	return (color_interp(COLOR0, COLOR1, (float)((z - fdf->map->z_min) /
		(fdf->map->z_max - fdf->map->z_min))));
}

/*
** DRAW_LINE *******************************************************************
**   ~ Draws a line from point `a` to point `b` in the main fdf window, using **
**     Bresenham's line generation algorithm. A description of how this works **
**     is available at:                                                       **
**     https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/    **
********************************************************************************
*/

void		draw_line(t_point a, t_point b, t_fdf *fdf)
{
	t_point	cur;
	t_point	delta;
	t_point	sign;
	int		err[2];

	delta = (t_point){ft_abs(b.x - a.x), ft_abs(b.y - a.y), 0, 0};
	sign = (t_point){a.x < b.x ? 1 : -1, a.y < b.y ? 1 : -1, 0, 0};
	err[0] = delta.x - delta.y;
	cur = a;
	while (!((cur.x == b.x) && (cur.y == b.y)))
	{
		ft_putpixel(fdf, cur.x, cur.y, color(cur, a, b, fdf));
		if ((err[1] = 2 * err[0]) > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += sign.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
