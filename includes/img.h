/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:21 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/14 20:37:07 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <math.h>
# include "typedefs.h"
# include "utils.h"
# include "vector.h"


t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere);
t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
t_intersection	intersect_plane(t_ray ray, t_plane *plane);

t_img	struct_img(t_scene *scene);

#endif // IMG_H
