/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:27:36 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 03:47:06 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	judge_intersect(t_ray ray, t_intersection *mx, t_objlist *lst)
{
	t_intersection	inter;

	if (lst->type == SPHERE)
	{
		inter = intersect_sphere(ray, lst->obj);
		if (mx->dist > inter.dist)
			*mx = inter;
	}
	else if (lst->type == CYLINDER)
	{
		inter = intersect_cylinder(ray, lst->obj);
		if (mx->dist > inter.dist)
			*mx = inter;
	}
	else if (lst->type == PLANE)
	{
		inter = intersect_plane(ray, lst->obj);
		if (mx->dist > inter.dist)
			*mx = inter;
	}
}

t_intersection	find_nearest_object(t_ray ray, t_scene *scene)
{
	t_objlist		*lst;
	t_intersection	mx;

	lst = scene->objects;
	mx.dist = INF;
	while (lst)
	{
		judge_intersect(ray, &mx, lst);
		lst = lst->next;
	}
	return (mx);
}
