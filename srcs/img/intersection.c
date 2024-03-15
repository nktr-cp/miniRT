/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:10:09 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/15 20:43:11 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			k[2];
	double			t;
	t_intersection	res;

	res.dist = INF;
	// a = 1;
	a = prod(ray.direction, ray.direction);
	b = 2 * prod(vector_sub(sphere->center, ray.origin), ray.direction);
	c = pow(norm(vector_sub(sphere->center, ray.origin)), 2.0) - sphere->diameter * sphere->diameter;
	d = pow(b,2) - 4 * a * c;
	if (d < 0)
		return (res);
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
	res.normal = normalize(vector_sub(res.coord, sphere->center));
	res.objptr = sphere;
	res.type = SPHERE;
	return (res);
}

t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			factor;
	double			t;
	t_intersection	res;

	res.dist = INF;
	a = pow(norm(cross(ray.direction, cylinder->normal)), 2.0);
	if (a == 0)
		return (res);
	b = 2 * prod(cross(ray.direction, cylinder->normal), cross(vector_sub(ray.origin, cylinder->origin), cylinder->normal));
	c = pow(norm(cross(vector_sub(ray.origin, cylinder->origin), cylinder->normal)), 2.0) - pow(cylinder->diameter, 2.0);
	// discriminant
	d = b * b - 4 * a * c;
	if (d < 0)
		return (res);
	factor = pow(d, 0.5);
	if (factor > b)
		t = (b + factor) / (2 * a);
	else
		t = (b - factor) / (2 * a);
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, t));
	res.dist = t;
	res.normal = normalize(vector_sub(vector_sub(res.coord, cylinder->origin), vector_mult(cylinder->normal, prod(vector_sub(res.coord, cylinder->origin), cylinder->origin))));
	res.objptr = cylinder;
	res.type = CYLINDER;
	return (res);
}

t_intersection	intersect_plane(t_ray ray, t_plane *plane)
{
	double			denominator;
	double			t;
	t_intersection	res;

	res.type = PLANE;
	res.dist = INF;
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
