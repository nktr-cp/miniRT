/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:10:09 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/14 22:48:03 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

t_intersection	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			factor;
	double			t;
	t_intersection	res;

	res.dist = INF;
	a = 1;
	// a = prod(ray.direction, ray.direction);
	b = 2 * prod(vector_sub(ray.origin, sphere->center), ray.direction);
	c = prod(vector_sub(ray.origin, sphere->center), vector_sub(ray.origin, sphere->center)) - sphere->diameter * sphere->diameter;
	d = pow(b,2) - 4 * a * c;
	if (d < 0)
		return (res);
	factor = pow(b * b - 4 * a * c, 0.5);
	if (factor > b)
		t = (b + factor) / (2 * a);
	else
		t = (b - factor) / (2 * a);
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, t));
	res.dist = t;
	res.normal = normalize(vector_sub(res.coord, sphere->center));
	res.objptr = sphere;
	res.type = SPHERE;
	return (res);
}

t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_intersection	res;

	res.dist = INF;
	// procedure here
	
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
	if (abs(denominator) == EPS)
		return (res);
	t = prod(vector_sub(plane->point, ray.origin), plane->normal) / denominator;
	res.dist = t;
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, t));
	res.normal = plane->normal;
	if (t < 0)
		res.normal = vector_mult(res.normal, -1);
	return (res);
}
