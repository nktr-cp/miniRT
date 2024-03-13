/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:09:42 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/13 16:25:14 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "typedefs.h"

t_vector	vector_add(const t_vector v1, const t_vector v2);
t_vector	vector_sub(const t_vector v1, const t_vector v2);
t_vector	cross(const t_vector v1, const t_vector v2);
double		norm(const t_vector v);
double		prod(const t_vector v1, const t_vector v2);


#endif // VECTOR_H
