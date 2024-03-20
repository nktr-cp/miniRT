/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:13:02 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 03:47:06 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_intersection	intersect_plane(t_ray ray, t_plane *plane)
{
	double			denominator;
	double			t;
	t_intersection	res;

	res.dist = INF;
	res.objptr = plane;
	res.type = PLANE;
	denominator = dot(ray.direction, plane->normal);
	if (fabs(denominator) < EPS)
		return (res);
	t = dot(vector_sub(plane->point, ray.origin), plane->normal) / denominator;
	if (t < 0)
		return (res);
	res.dist = t;
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, t));
	res.normal = plane->normal;
	return (res);
}
