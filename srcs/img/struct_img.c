/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:41:34 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/15 20:41:02 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

// void	put_color_pixel(t_img *img, int x, int y, t_color color)
// {
	
// }

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

t_img	struct_img(t_scene *scene)
{
	int		i;
	int		j;
	t_img	img;
	t_ray	ray;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			// カメラの位置を元にrayをつくる
			ray = generate_ray(scene, i, j);
			// 最初にぶつかるobjectを判定
		}
	}
	img.img = NULL;
	return (img);
}
