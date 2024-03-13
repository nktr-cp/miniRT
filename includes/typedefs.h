/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:19:19 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 21:15:38 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include "objlist.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_sphere
{
	t_vector	center;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	normal;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector	origin;
	t_color		color;
	double		brightness;
}	t_light;

typedef struct s_amblight
{
	t_color	color;
	double	ratio;
}	t_amblight;

typedef enum e_objtype
{
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_objtype;

typedef struct s_objlist
{
	void				*obj;
	t_objtype			type;
	struct s_objlist	*next;
}	t_objlist;

typedef struct s_scene
{
	t_camera	camera;
	t_amblight	amblight;
	t_objlist	*objects;
}	t_scene;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_scene	scene;
}	t_data;

#endif
