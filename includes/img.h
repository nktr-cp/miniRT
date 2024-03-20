/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:21 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 00:33:56 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

// debug
# include <stdio.h>
# include <assert.h>

# include <math.h>
# include <mlx.h>
# include "typedefs.h"
# include "utils.h"
# include "vector.h"

void			init_camera(t_camera *camera);

t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere);
t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
t_intersection	intersect_plane(t_ray ray, t_plane *plane);

t_img			struct_img(t_scene *scene);
t_intersection	find_nearest_object(t_ray ray, t_scene *scene);

t_color			get_diffused_color(double cosine, t_color objectcolor, t_light *light);
t_color			get_ambient_color(t_color objectcolor, t_amblight *light);
t_color			whatcolorisit(t_ray ray, t_scene *scene);

//debug
# define GREEN (t_color){60, 120, 60}
# define BLACK (t_color){0, 0, 0}
# define RED (t_color){120, 60, 60}

#endif // IMG_H
