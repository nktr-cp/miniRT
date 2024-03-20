/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:50:55 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/21 03:50:57 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <math.h>
# include <mlx.h>
# include "typedefs.h"
# include "utils.h"
# include "vector.h"

void			init_camera(t_camera *camera);

void			put_color_pixel(t_img *img, int x, int y, t_color color);
int				minirt_close(t_scene *scene);
void			mlx_setup(t_img *img);
void			mlx_render(t_scene *scene, t_img *img);

t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere);
t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
t_intersection	intersect_plane(t_ray ray, t_plane *plane);

t_img			struct_img(t_scene *scene);
t_intersection	find_nearest_object(t_ray ray, t_scene *scene);

t_color			get_diffused_color(double cosine,
					t_color objectcolor, t_light *light);
t_color			get_ambient_color(t_color objectcolor, t_amblight *light);
t_color			whatcolorisit(t_ray ray, t_scene *scene);

#endif // IMG_H
