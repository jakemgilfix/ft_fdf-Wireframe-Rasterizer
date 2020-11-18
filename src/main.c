/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:00:16 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 11:56:01 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** SET_HOOKS *******************************************************************
**   ~ Sets mouse button/keyboard bindings, allowing user control of the      **
**     program.                                                               **
********************************************************************************
*/

static void	set_hooks(t_fdf *fdf)
{
	mlx_do_key_autorepeatoff(fdf->mlx);
	mlx_hook(fdf->win, 2, 0, key_press_hook, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press_hook, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release_hook, fdf);
	mlx_hook(fdf->win, 6, 0, motion_hook, fdf);
	mlx_hook(fdf->win, 17, 0, exit_hook, fdf);
}

/*
** MAIN ************************************************************************
**   ~ If the number of arguments is 2, initializes all the structures, reads **
**     the input file, and draws the map in a persistent window.              **
********************************************************************************
*/

int			main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
	{
		ft_putendl_fd(ERR_USAGE, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	fdf_init(&fdf, av[1]);
	draw(&fdf);
	set_hooks(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
