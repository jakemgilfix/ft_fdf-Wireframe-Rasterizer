/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:01:07 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 14:39:17 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** MAP_INIT ********************************************************************
**   ~ Initializes a structure of type `t_map`, returning a pointer to the    **
**     malloc()ed structure.                                                  **
********************************************************************************
*/

static t_map	*map_init(int fd)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(*map))))
	{
		close(fd);
		ft_putendl_fd(ERR_MAP_ALLOC, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	map->height = 0;
	map->width = 0;
	map->z_max = -__INT_MAX__ - 1;
	map->z_min = __INT_MAX__;
	return (map);
}

/*
** SB_INIT *********************************************************************
**   ~ Initializes the sidebar. This will contain:                            **
**       (1) A background (color defined in "fdf.h")                          **
**       (2) A menu listing the mouse/keyboard controls                       **
********************************************************************************
*/

static void		sb_init(t_fdf *fdf)
{
	fill_image(fdf->sb_data, SB_H, SB_W, SB_COLOR);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->sb_img, 0, 0);
	draw_menu(fdf);
}

/*
** WIN_INIT ********************************************************************
**   ~ Initializes the two windows -- a "main" window and a "sidebar" -- as   **
**     well as the two images they contain. Additionally, fetches the data    **
**     addresses of these two images (via mlx_get_data_addr()) and stores     **
**     them as integer arrays for easier manipulation.                        **
********************************************************************************
*/

static void		win_init(t_fdf *fdf)
{
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, WIN_TITLE);
	fdf->main_img = mlx_new_image(fdf->mlx, MAIN_W, MAIN_H);
	fdf->sb_img = mlx_new_image(fdf->mlx, SB_W, SB_H);
	fdf->sb_data = (int *)mlx_get_data_addr(fdf->sb_img, &(fdf->bpp),
		&(fdf->size_l), &(fdf->endian));
	fdf->main_data = (int *)mlx_get_data_addr(fdf->main_img, &(fdf->bpp),
		&(fdf->size_l), &(fdf->endian));
	sb_init(fdf);
}

/*
** CAMERA_INIT *****************************************************************
**   ~ Initializes the `t_camera` structure used to store the projection type **
**     as well as the viewing perspective, returning a pointer to it.         **
********************************************************************************
*/

static t_camera	*camera_init(int height, int width)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(*camera))))
	{
		ft_putendl_fd(ERR_CAMERA, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	camera->projection = ISO;
	camera->zoom = ft_int_min(MAIN_W / width / 2, MAIN_H / height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}

/*
** FDF_INIT ********************************************************************
**   ~ Opens the file given as argument to the program, reads the file into a **
**     map structure, initializes `mlx`, `camera`, and `mouse` structures,    **
**     as well as the two windows, and stores these in the given `fdf`        **
**     structure.                                                             **
********************************************************************************
*/

void			fdf_init(t_fdf *fdf, const char *filename)
{
	fdf->filename = filename;
	if (!((fdf->fd = open(filename, O_RDONLY)) > 0))
	{
		ft_putendl_fd(ERR_FILE, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	fdf->map = map_init(fdf->fd);
	if (!read_map(fdf->map, fdf->fd))
	{
		close(fdf->fd);
		ft_memdel((void **)&(fdf->map));
		ft_putendl_fd(ERR_INV_MAP, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	fdf->mlx = mlx_init();
	fdf->camera = camera_init(fdf->map->height, fdf->map->width);
	if ((fdf->map->z_max - fdf->map->z_min) >
		ft_int_max(fdf->map->height, fdf->map->width))
		fdf->camera->z_divisor = (fdf->map->z_max - fdf->map->z_min) /
			ft_int_max(fdf->map->height, fdf->map->width);
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	fdf->mouse->is_pressed = FALSE;
	win_init(fdf);
}
