/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:59:11 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 14:10:29 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** NOTES ***********************************************************************
**  ~ If you suck at math and/or life, check out the following resource on    **
**    rotation matrices:                                                      **
**    https://en.wikipedia.org/wiki/Rotation_matrix                           **
********************************************************************************
*/

/*
** X_ROT ***********************************************************************
**   ~ Applies the rotation matrix R_x_(alpha) to the vector (x, y, z),       **
**     projecting it onto a plane at angle `alpha` from the x-axis.           **
**     R_x_(alpha) is the rotation matrix that applies the following          **
**     transformation:                                                        **
**        x' = x                                  (Primed == New,             **
**        y' = y*cos(alpha) - z*sin(alpha)         Unprimed == Old)           **
**        z' = y*sin(alpha) + z*cos(alpha)                                    **
********************************************************************************
*/

static void	x_rot(int *y, int *z, double alpha)
{
	int y_prev;

	y_prev = *y;
	*y = y_prev * cos(alpha) - *z * sin(alpha);
	*z = y_prev * sin(alpha) + *z * cos(alpha);
}

/*
** Y_ROT ***********************************************************************
**   ~  Applies the rotation matrix R_y_(beta) to the vector (x, y, z),       **
**      projecting it onto a plane at angle `beta` from the y-axis.           **
**      R_y_(beta) is the rotation matrix that applies the following          **
**      transformation:                                                       **
**        x' = x*cos(beta) + z*sin(beta)          (Primed == New,             **
**        y' = y                                   Unprimed == Old)           **
**        z' = -x*sin(beta) + z*cos(beta)                                     **
********************************************************************************
*/

static void	y_rot(int *x, int *z, double beta)
{
	int x_prev;

	x_prev = *x;
	*x = x_prev * cos(beta) + *z * sin(beta);
	*z = -x_prev * sin(beta) + *z * cos(beta);
}

/*
** Z_ROT ***********************************************************************
**   ~ Applies the rotation matrix R_z_(gamma) to the vector (x, y, z),       **
**     projecting it onto a plane at angle `gamma` from the z-axis.           **
**     R_z_(gamma) is the rotation matrix that applies the following          **
**     transformation:                                                        **
**       x' = x*cos(gamma) - y*sin(gamma)        (Primed == New,              **
**       y' = x*sin(gamma) + y*cos(gamma)         Unprimed == Old)            **
**       z' = z                                                               **
********************************************************************************
*/

static void	z_rot(int *x, int *y, double gamma)
{
	int x_prev;
	int y_prev;

	x_prev = *x;
	y_prev = *y;
	*x = x_prev * cos(gamma) - y_prev * sin(gamma);
	*y = x_prev * sin(gamma) + y_prev * cos(gamma);
}

/*
** ISO *************************************************************************
**   ~ Performs a "true" isometric projection (versus a 2:1), using an angle  **
**     of 30 degrees. Recall:                                                 **
**       sin(30d) = 1/2                                                       **
**       cos(30d) = sqrt(3) / 2                                               **
**     A far more detailed account of how this all works can be found here:   **
**     https://www.kirupa.com/developer/actionscript/isometric_transforms.htm **
********************************************************************************
*/

static void	iso(int *x, int *y, int z)
{
	int x_prev;
	int y_prev;

	x_prev = *x;
	y_prev = *y;
	*x = (x_prev - y_prev) * sqrt(3) / 2;
	*y = -z + (x_prev + y_prev) * 0.500000;
}

/*
** PROJECT *********************************************************************
**   ~ Projects the 3-D point onto the 2-D plane as viewed from the angle     **
**     specified by the various `camera` parameters. Read the comments above  **
**     for more details.                                                      **
********************************************************************************
*/

t_point		project(t_point pt, t_fdf *fdf)
{
	pt.x *= fdf->camera->zoom;
	pt.y *= fdf->camera->zoom;
	pt.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	pt.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	pt.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	x_rot(&pt.y, &pt.z, fdf->camera->alpha);
	y_rot(&pt.x, &pt.z, fdf->camera->beta);
	z_rot(&pt.x, &pt.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		iso(&pt.x, &pt.y, pt.z);
	pt.x += (MAIN_W) / 2 + fdf->camera->x_offset;
	pt.y += (MAIN_H + fdf->map->height * fdf->camera->zoom) / 2 +
		fdf->camera->y_offset;
	return (pt);
}
