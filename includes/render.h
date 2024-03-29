/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:46:42 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 03:48:09 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

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
t_intersection	find_nearest_object(t_ray ray, t_scene *scene);

t_color			get_diffused_color(double cosine,
					t_color objectcolor, t_light *light);
t_color			get_ambient_color(t_color objectcolor, t_amblight *light);
t_color			whatcolorisit(t_ray ray, t_scene *scene);

void			render(t_scene *scene);

#endif // RENDER_H
