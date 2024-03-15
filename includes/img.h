/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:43:21 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/15 19:51:22 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <math.h>
# include "typedefs.h"
# include "utils.h"
# include "vector.h"
# include "mlx.h"

t_img			struct_img(t_scene *scene);
t_intersection	*find_nearest_object(t_ray ray, t_scene *scene);

# define EPSILON 0.0001

#endif // IMG_H
