/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:59:56 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 14:15:08 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** TRANSLATE *******************************************************************
**   ~ Translates the wireframe in the direction specified by the user.       **
********************************************************************************
*/

void	translate(int key, t_fdf *fdf)
{
	if (key == ARR_LEFT || key == ARR_RIGHT)
		fdf->camera->x_offset += (key == ARR_RIGHT) ? TRANS_AMT : -TRANS_AMT;
	if (key == ARR_UP || key == ARR_DOWN)
		fdf->camera->y_offset += (key == ARR_DOWN) ? TRANS_AMT : -TRANS_AMT;
	draw(fdf);
}

/*
** SET_CAMERA_VIEW *************************************************************
**   ~ Sets the camera view : {(I)sometric, (P)arallel} as specified by the   **
**     user.                                                                  **
********************************************************************************
*/

void	set_camera_view(int key, t_fdf *fdf)
{
	fdf->camera->projection = (key == KEY_I) ? ISO : PARALLEL;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	draw(fdf);
}

/*
** ZOOM ************************************************************************
**   ~ Zooms in/out of wireframe rendering.                                   **
********************************************************************************
*/

void	zoom(int button, t_fdf *fdf)
{
	fdf->camera->zoom += (button == MWHEEL_UP) ? ZOOM_AMT : -ZOOM_AMT;
	fdf->camera->zoom = (fdf->camera->zoom < 1) ? 1 : fdf->camera->zoom;
	draw(fdf);
}

/*
** ROTATE **********************************************************************
**   ~ Rotate the `camera` angle to change the viewing angle/perspective.     **
********************************************************************************
*/

void	rotate(int x_prev, int y_prev, t_fdf *fdf)
{
	fdf->camera->beta += (fdf->mouse->location[0] - x_prev) * MOUSE_SENS;
	fdf->camera->alpha -= (fdf->mouse->location[1] - y_prev) * MOUSE_SENS;
	draw(fdf);
}
