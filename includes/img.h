/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:21 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/14 19:20:31 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <math.h>
# include "typedefs.h"
# include "utils.h"
# include "vector.h"


double	intersect_sphere(t_ray ray, t_sphere *sphere);
double	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
double	intersect_plane(t_ray ray, t_plane *plane);

t_img	struct_img(t_scene *scene);

#endif // IMG_H
