/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:10:09 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/18 15:42:05 by knishiok         ###   ########.fr       */
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
		res.normal = vector_mult(res.normal, -1);
	return (res);
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
	abc[0] = prod(ray.direction, ray.direction);
	abc[1] = 2 * prod(vector_sub(ray.origin, sphere->center), ray.direction);
	abc[2] = pow(norm(vector_sub(ray.origin, sphere->center)), 2)
		- pow(sphere->diameter, 2);
	d = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (d < 0)
		return (res);
	k[0] = (-abc[1] + pow(d, 0.5)) * 0.5 / abc[0];
	k[1] = (-abc[1] - pow(d, 0.5)) * 0.5 / abc[0];
	if (k[0] < 0 && k[1] < 0)
		return (res);
	else if (k[0] > 0 && k[1] > 0)
		res.dist = fmin(k[0], k[1]);
	else if (k[0] > 0)
		res.dist = k[0];
	else
		res.dist = k[1];
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, res.dist));
	res.normal = normalize(vector_sub(res.coord, sphere->center));
	return (res);
}

t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	double			abc[3];
	double			d;
	double			k[2];
	double			t;
	t_intersection	res;

	res.dist = INF;
	res.objptr = cylinder;
	res.type = CYLINDER;
	abc[0] = pow(norm(cross(ray.direction, cylinder->normal)), 2.0);
	if (abc[0] == 0)
		return (res);
	abc[1] = 2 * prod(cross(ray.direction, cylinder->normal), cross(vector_sub(ray.origin, cylinder->origin), cylinder->normal));
	abc[2] = pow(norm(cross(vector_sub(ray.origin, cylinder->origin), cylinder->normal)), 2.0) - pow(cylinder->diameter, 2.0);
	d = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (d < 0)
		return (res);
	k[0] = (-abc[1] + pow(d, 0.5)) * 0.5;
	k[1] = (-abc[1] - pow(d, 0.5)) * 0.5;
	if (k[0] < 0 && k[1] < 0)
		return (res);
	else if (k[0] > 0 && k[1] > 0)
		t = fmin(k[0], k[1]);
	else if (k[0] > 0)
		t = k[0];
	else
		t = k[1];
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, t));
	res.dist = t;
	res.normal = normalize(vector_sub(vector_sub(res.coord, cylinder->origin), vector_mult(cylinder->normal, prod(vector_sub(res.coord, cylinder->origin), cylinder->origin))));
	return (res);
}
