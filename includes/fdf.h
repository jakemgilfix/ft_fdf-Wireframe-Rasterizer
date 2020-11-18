/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:27:14 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 08:55:49 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** HEADER FILES ================================================================
*/

# include <math.h>
# include "../libmlx/mlx.h"
# include "../libft/libft.h"

/*
** MLX-RELATED SETTINGS ========================================================
*/

# define WIN_TITLE		"ft_wireframe ~ jgilfix"
# define WIN_H			1200
# define WIN_W			1600
# define MAIN_H			WIN_H
# define MAIN_W			1200
# define MAIN_COLOR		0x00212121
# define SB_H			WIN_H
# define SB_W			400
# define SB_COLOR		0x00303030
# define TEXT_COLOR		0x00ffffff

/*
** PINK AND CYAN ===============================================================
*/

# define COLOR0     0x0066d8ee
# define COLOR1     0x00f82a71

/*
** KEY MACROS ==================================================================
*/

# define MOUSE1			1
# define MOUSE2			2
# define MOUSE3			3
# define MWHEEL_UP		4
# define MWHEEL_DOWN	5

# define KEY_PLUS		24
# define KEY_MINUS		27

# define KEY_I			34
# define KEY_P			35

# define KEY_ESC		53

# define ARR_LEFT		123
# define ARR_RIGHT		124
# define ARR_DOWN		125
# define ARR_UP			126

/*
** KEYBOARD CONTROL SETTINGS ===================================================
*/

# define TRANS_AMT		15
# define ZOOM_AMT		1
# define MOUSE_SENS		0.0025

/*
** ERROR MESSAGES ==============================================================
*/

# define ERR_USAGE		"usage: ./fdf <filename>"
# define ERR_FILE		"Error: Invalid filename"
# define ERR_MAP_ALLOC	"Error: Allocation of map structure failed"
# define ERR_INV_MAP	"Error: Invalid map"
# define ERR_CAMERA		"Error: malloc() be trippin' sometimes"

/*
** DATA STRUCTURES =============================================================
*/

typedef enum
{
	FALSE,
	TRUE
}	t_boolean;

typedef struct	s_map
{
	int	height;
	int	width;
	int	z_min;
	int	z_max;
	int	*z_coords;
}				t_map;

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct	s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}				t_camera;

typedef struct	s_mouse
{
	t_boolean	is_pressed;
	int			location[2];
}				t_mouse;

typedef struct	s_fdf
{
	const char	*filename;
	int			fd;
	t_map		*map;
	void		*mlx;
	void		*win;
	void		*main_img;
	void		*sb_img;
	int			*main_data;
	int			*sb_data;
	int			bpp;
	int			size_l;
	int			endian;
	t_camera	*camera;
	t_mouse		*mouse;
}				t_fdf;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

/*
** DRAW.C ======================================================================
*/

void			fill_image(int *img, size_t height, size_t width, int color);
void			draw(t_fdf *fdf);

/*
** GFX_TOOLS.C =================================================================
*/

void			draw_line(t_point a, t_point b, t_fdf *fdf);

/*
** HOOKS.C =====================================================================
*/

int				key_press_hook(int key, void *param);
int				exit_hook(void *param);
int				mouse_press_hook(int button, int x, int y, void *param);
int				mouse_release_hook(int button, int x, int y, void *param);
int				motion_hook(int x, int y, void *param);

/*
** INIT.C ======================================================================
*/

void			fdf_init(t_fdf *fdf, const char *filename);

/*
** INPUT.C =====================================================================
*/

t_boolean		read_map(t_map *map, int fd);

/*
** INPUT2.C ====================================================================
*/

void			lst_to_arr(t_list *head, t_map *map);

/*
** USER_CONTROLS.C =============================================================
*/

void			translate(int key, t_fdf *fdf);
void			set_camera_view(int key, t_fdf *fdf);
void			zoom(int button, t_fdf *fdf);
void			rotate(int x_prev, int y_prev, t_fdf *fdf);

/*
** MENU.C ======================================================================
*/

void			draw_menu(t_fdf *fdf);

/*
** PROJECTION.C ================================================================
*/

t_point			project(t_point pt, t_fdf *fdf);

#endif
