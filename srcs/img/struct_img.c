/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:41:34 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/14 19:31:34 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

void	put_color_pixel(t_img *img, int x, int y, t_color color)
{
	
}

t_ray	generate_ray(t_scene *scene, const int x, const int y)
{
	t_ray		res;
	double		mx;
	double		my;
	t_vector	xvec;
	t_vector	yvec;

	res.origin = scene->camera.origin;
	mx = x - WIDTH * 0.5;
	my = y - HEIGHT * 0.5;
	xvec = vector_mult(scene->camera.ex, mx);
	yvec = vector_mult(scene->camera.ey, my);
	res.direction = vector_add(scene->camera.origin, vector_add(xvec, yvec));
	return (res);
}

void	*judge_intersect(t_ray ray, double *dist, void **res, t_objlist *lst)
{
	if (lst->type == SPHERE && *dist < intersect_sphere(ray, lst->obj))
	{
		*dist = intersect_sphere(ray, lst->obj);
		*res = lst->obj;
	}
	else if (lst->type == CYLINDER && *dist < intersect_cylinder(ray, lst->obj))
	{
		*dist = intersect_cylinder(ray, lst->obj);
		*res = lst->obj;
	}
	else if (lst->type == PLANE && *dist < intersect_plane(ray, lst->obj))
	{
		*dist = intersect_plane(ray, lst->obj);
		*res = lst->obj;
	}
}

void	*find_nearest_object(t_ray ray, t_scene *scene)
{
	t_objlist	*lst;
	double		dist;
	void		*res;

	lst = scene->objects;
	dist = INF;
	res = NULL;
	while (lst)
	{
		judge_intersect(ray, &dist, &res, lst);
		lst = lst->next;
	}
	return (res);
}

t_img	struct_img(t_scene *scene)
{
	int		i;
	int		j;
	t_img	img;
	t_ray	ray;
	void	*obj;
	t_color	color;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			color.r = color.g = color.b = 0;
			// カメラの位置を元にrayをつくる
			ray = generate_ray(scene, i, j);
			// 最初にぶつかるobjectを判定
			obj = find_nearest_object(ray, scene);
			if (obj)
			{
				// color = calculation here
			}
		}
	}
	return (img);
}
