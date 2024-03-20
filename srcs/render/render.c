/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:41:40 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 04:09:45 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_ray	generate_ray(t_scene *scene, const int x, const int y)
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

void	render(t_scene *scene)
{
	int				idx[2];
	t_img			img;
	t_ray			ray;
	t_intersection	it;
	t_color			color;

	mlx_setup(&img);
	init_camera(&scene->camera);
	idx[0] = -1;
	while (++idx[0] < WIDTH)
	{
		idx[1] = -1;
		while (++idx[1] < HEIGHT)
		{
			color = (t_color){0, 60, 144};
			ray = generate_ray(scene, idx[0], idx[1]);
			it = find_nearest_object(ray, scene);
			if (it.dist != INF)
				color = whatcolorisit(ray, scene);
			put_color_pixel(&img, idx[0], idx[1], color);
		}
	}
	mlx_render(scene, &img);
}
