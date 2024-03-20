/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:13:31 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/20 23:33:18 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static bool	choose_dist(double k[2], double *dist)
{
	if (k[0] < 0 && k[1] < 0)
		return (false);
	else if (k[0] > 0 && k[1] > 0)
		*dist = fmin(k[0], k[1]);
	else if (k[0] > 0)
		*dist = k[0];
	else
		*dist = k[1];
	return (true);
}

t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	double			abc[3];
	double			d;
	double			k[2];
	t_intersection	res;

	res.dist = INF;
	res.objptr = sphere;
	res.type = SPHERE;
	abc[0] = 1.0;
	abc[1] = 2 * prod(vector_sub(ray.origin, sphere->center), ray.direction);
	abc[2] = pow(norm(vector_sub(ray.origin, sphere->center)), 2)
		- pow(sphere->diameter, 2);
	d = abc[1] * abc[1] - 4 * abc[2];
	if (d < 0)
	{
		// printf("%f %f %f\n", abc[0], abc[1], abc[2]);
		return (res);
	}
	k[0] = (-abc[1] + pow(d, 0.5)) * 0.5;
	k[1] = (-abc[1] - pow(d, 0.5)) * 0.5;
	if (!choose_dist(k, &res.dist))
		return (res);
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, res.dist));
	res.normal = normalize(vector_sub(res.coord, sphere->center));
	return (res);
}
