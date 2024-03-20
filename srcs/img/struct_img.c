/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:41:34 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/20 16:22:07 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

void	put_color_pixel(t_img *img, int x, int y, t_color color)
{
	unsigned int	col;

	col = color_to_uint(color);
	*(unsigned int *)
		(img->addr + y * img->line_length
			+ x * (img->bits_per_pixel / 8)) = col;
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
	res.direction = normalize(vector_add(scene->camera.to_center,
				vector_add(xvec, yvec)));
	return (res);
}

void	judge_intersect(t_ray ray, t_intersection *mx, t_objlist *lst)
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

t_img	struct_img(t_scene *scene)
{
	int				i;
	int				j;
	t_img			img;
	t_ray			ray;
	t_intersection	it;
	t_color			color;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_camera(&scene->camera);

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			color = BLACK;
			ray = generate_ray(scene, i, j);
			it = find_nearest_object(ray, scene);
			if (it.dist != INF)
				color = whatcolorisit(ray, scene);
			put_color_pixel(&img, i, j, color);
		}
	}
	return (img);
}
