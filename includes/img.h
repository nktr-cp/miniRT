/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:21 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/15 22:00:47 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

// debug
# include <stdio.h>
# include <assert.h>

# include <math.h>
# include "typedefs.h"
# include "utils.h"
# include "vector.h"
# include <mlx.h>

void	init_camera(t_camera *camera);

t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere);
t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
t_intersection	intersect_plane(t_ray ray, t_plane *plane);

t_img			struct_img(t_scene *scene);
t_intersection	find_nearest_object(t_ray ray, t_scene *scene);

# define EPSILON 0.0001

#endif // IMG_H
