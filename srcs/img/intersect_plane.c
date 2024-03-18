/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:13:02 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/18 17:38:04 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

t_intersection	intersect_plane(t_ray ray, t_plane *plane)
{
	double			denominator;
	double			t;
	t_intersection	res;

	res.dist = INF;
	res.objptr = plane;
	res.type = PLANE;
	denominator = prod(ray.direction, plane->normal);
	if (fabs(denominator) < EPS)
		return (res);
	t = prod(vector_sub(plane->point, ray.origin), plane->normal) / denominator;
	res.dist = t;
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, t));
	res.normal = plane->normal;
	if (t < 0)
	{
		res.dist *= -1;
		res.normal = vector_mult(res.normal, -1);
	}
	return (res);
}
