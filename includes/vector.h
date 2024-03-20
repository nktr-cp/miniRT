/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:09:42 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 03:09:19 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "typedefs.h"

t_vector	make_vector(double x, double y, double z);
t_vector	vector_add(const t_vector v1, const t_vector v2);
t_vector	vector_sub(const t_vector v1, const t_vector v2);
t_vector	vector_mult(const t_vector v, double scalar);

t_vector	cross(const t_vector v1, const t_vector v2);
double		norm(const t_vector v);
double		dot(const t_vector v1, const t_vector v2);
t_vector	normalize(t_vector v);

#endif // VECTOR_H
