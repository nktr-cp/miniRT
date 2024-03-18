/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:41:34 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/18 15:54:55 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

void	put_color_pixel(t_img *img, int x, int y, t_color color)
{
	unsigned int	col;

	col = color_to_int(color);
	*(unsigned int *)(img->addr + y * img->line_length + x * (img->bits_per_pixel / 8)) = col;
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
	res.direction = normalize(vector_add(scene->camera.to_center, vector_add(xvec, yvec)));
	return (res);
}

void	judge_intersect(t_ray ray, t_intersection *mx, t_objlist *lst)
{
	if (lst->type == SPHERE && mx->dist > intersect_sphere(ray, lst->obj).dist)
		*mx = intersect_sphere(ray, lst->obj);
	else if (lst->type == CYLINDER && mx->dist > intersect_cylinder(ray, lst->obj).dist)
		*mx = intersect_cylinder(ray, lst->obj);
	else if (lst->type == PLANE && mx->dist > intersect_plane(ray, lst->obj).dist)
		*mx = intersect_plane(ray, lst->obj);
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
	int			i;
	int			j;
	t_img		img;
	t_ray		ray;
	t_intersection	it;
	t_color		color;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "miniRT");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_camera(&scene->camera);

	double max_dist = 0;
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			color.r = color.g = color.b = 0;
			// カメラの位置を元にrayをつくる
			ray = generate_ray(scene, i, j);
			// 最初にぶつかるobjectを判定
			it = find_nearest_object(ray, scene);
			if (it.dist != INF)
				max_dist = fmax(max_dist, it.dist);
		}
	}


	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			color.r = color.g = color.b = 0;
			// カメラの位置を元にrayをつくる
			ray = generate_ray(scene, i, j);
			// 最初にぶつかるobjectを判定
			it = find_nearest_object(ray, scene);
			if (it.dist != INF)
			{
				// printf("%f\n", it.dist);
				color.r = color.b = 255 * it.dist / max_dist;
			}
			put_color_pixel(&img, i, j, color);
		}
	}
	return (img);
}
