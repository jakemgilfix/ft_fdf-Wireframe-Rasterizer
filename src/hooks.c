/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:42:49 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 13:18:05 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
********************************************************************************
** NOTE: This code makes heavy use of the documentation that Mason put        **
**       together on Github: https://github.com/qst0/ft_libgfx                **
********************************************************************************
*/

#include "fdf.h"

/*
** EXIT_HOOK *******************************************************************
**   ~ This hook is called when the user presses [ESC] to terminate fdf.      **
********************************************************************************
*/

int	exit_hook(void *param)
{
	(void)param;
	exit(0);
}

/*
** KEY_PRESS_HOOK **************************************************************
**   ~ This hook handles user keypresses, taking the appropriate action       **
**     according to which key was pressed. Actions include:                   **
**       [ESC]    Exit Program                                                **
**       [ARROWS] Translate wireframe in <direction>                          **
**       [I/P]    Set Projection Type : {(I)sometric | (P)arallel}            **
********************************************************************************
*/

int	key_press_hook(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESC)
		(void)exit_hook(param);
	else if (key == ARR_LEFT || key == ARR_RIGHT ||
		key == ARR_DOWN || key == ARR_UP)
		translate(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		set_camera_view(key, fdf);
	return (0);
}

/*
** MOUSE_PRESS_HOOK ************************************************************
**   ~ This hook handles user mouse clicks, taking the appropriate action     **
**     according to which mouse button was clicked. Actions include:          **
**       [MOUSE1] Set fdf->mouse->is_pressed                                  **
**       [MWHEEL] Zoom in/out                                                 **
********************************************************************************
*/

int	mouse_press_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MWHEEL_UP || button == MWHEEL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE1)
		fdf->mouse->is_pressed = TRUE;
	return (0);
}

/*
** MOUSE_RELEASE_HOOK **********************************************************
**   ~ This hook handles when the user releases a mouse button. This simply   **
**     resets fdf->mouse->is_pressed to `FALSE`.                              **
********************************************************************************
*/

int	mouse_release_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)button;
	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = FALSE;
	return (0);
}

/*
** MOTION_HOOK *****************************************************************
**   ~ This hook handles user mouse movement. If MOUSE1 is pressed, tracks    **
**     the direction of mouse movement, allowing the user to rotate the       **
**     wireframe in the main window.                                          **
********************************************************************************
*/

int	motion_hook(int x, int y, void *param)
{
	t_fdf	*fdf;
	int		x_prev;
	int		y_prev;

	fdf = (t_fdf *)param;
	x_prev = fdf->mouse->location[0];
	y_prev = fdf->mouse->location[1];
	fdf->mouse->location[0] = x;
	fdf->mouse->location[1] = y;
	if (fdf->mouse->is_pressed)
		rotate(x_prev, y_prev, fdf);
	return (0);
}
