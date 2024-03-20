/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:13:51 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 02:50:04 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static bool	choose_dist(double k[2], t_intersection *res)
{
	if (k[0] < 0 && k[1] < 0)
		return (false);
	else if (k[0] < 0)
	{
		assert(k[1] >= 0);
		if (k[1] < res->dist)
		{
			res->dist = k[1];
			return (true);
		}
	}
	else if (k[1] < 0)
	{
		assert(k[0] >= 0);
		if (k[0] < res->dist)
		{
			res->dist = k[0];
			return (true);
		}
	}
	else
	{
		assert(k[0] >= 0 && k[1] >= 0);
		if (k[0] < k[1] && k[0] < res->dist)
		{
			res->dist = k[0];
			return (true);
		}
		else if (k[1] < k[0] && k[1] < res->dist)
		{
			res->dist = k[1];
			return (true);
		}
	}
	return (false);
}

static bool	valid_range(double dist, t_cylinder *cylinder)
{
	return (dist >= 0 && dist <= cylinder->height);
}

static bool	has_intersection(double abc[3], double k[2],
	t_ray ray, t_cylinder *cylinder)
{
	t_vector	inter1;
	t_vector	inter2;
	double		dist1;
	double		dist2;
	double		d;

	d = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (d < 0)
		return (false);
	k[0] = (-abc[1] + pow(d, 0.5)) * 0.5 / abc[0];
	k[1] = (-abc[1] - pow(d, 0.5)) * 0.5 / abc[0];
	inter1 = vector_add(ray.origin, vector_mult(ray.direction, k[0]));
	inter2 = vector_add(ray.origin, vector_mult(ray.direction, k[1]));
	dist1 = prod(vector_sub(inter1, cylinder->origin), cylinder->normal);
	dist2 = prod(vector_sub(inter2, cylinder->origin), cylinder->normal);
	if (!valid_range(dist1, cylinder) && !valid_range(dist2, cylinder))
		return (false);
	else if (!valid_range(dist1, cylinder))
		k[0] = -1;
	else if (!valid_range(dist2, cylinder))
		k[1] = -1;
	return (true);
}

static void	hit_base(t_ray ray, t_cylinder *cylinder, t_intersection *res)
{
	t_plane			plane;
	t_intersection	inter;
	t_vector		upper;

	plane = (t_plane){cylinder->origin, vector_mult(cylinder->normal, -1), cylinder->color};
	inter = intersect_plane(ray, &plane);
	if (norm(vector_sub(inter.coord, cylinder->origin)) <= cylinder->diameter)
		*res = inter;
	upper = vector_add(cylinder->origin, vector_mult(cylinder->normal, cylinder->height));
	plane = (t_plane){upper, cylinder->normal, cylinder->color};
	inter = intersect_plane(ray, &plane);
	if (norm(vector_sub(inter.coord, upper)) <= cylinder->diameter && res->dist > inter.dist)
		*res = inter;
}

t_intersection	intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	double			abc[3];
	double			k[2];
	t_intersection	res;

	res.dist = INF;
	hit_base(ray, cylinder, &res);
	res.type = CYLINDER;
	res.objptr = cylinder;
	abc[0] = pow(norm(cross(ray.direction, cylinder->normal)), 2.0);
	if (abc[0] == 0)
		return (res);
	abc[1] = 2 * prod(cross(ray.direction, cylinder->normal),
			cross(vector_sub(ray.origin, cylinder->origin), cylinder->normal));
	abc[2] = pow(norm(cross(vector_sub(ray.origin, cylinder->origin),
					cylinder->normal)), 2.0) - pow(cylinder->diameter, 2.0);
	if (!has_intersection(abc, k, ray, cylinder))
		return (res);
	if (!choose_dist(k, &res))
		return (res);
	res.coord = vector_add(ray.origin, vector_mult(ray.direction, res.dist));
	res.normal = normalize(vector_sub(vector_sub(res.coord, cylinder->origin),
				vector_mult(cylinder->normal,
					prod(vector_sub(res.coord, cylinder->origin),
						cylinder->normal))));
	return (res);
}
