/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:37:10 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 03:47:06 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_color_pixel(t_img *img, int x, int y, t_color color)
{
	unsigned int	col;

	col = color_to_uint(color);
	*(unsigned int *)
		(img->addr + y * img->line_length
			+ x * (img->bits_per_pixel / 8)) = col;
}

void	mlx_setup(t_img *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "miniRT");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

int	minirt_close(t_scene *scene)
{
	(void)scene;
	// minirt_cleanup(scene);
	minirt_exit(NULL, EXIT_SUCCESS);
	return (0);
}

static int	minirt_key(int key, void *data)
{
	(void)data;
	if (key == 53)
		minirt_close(data);
	return (0);
}

void	mlx_render(t_scene *scene, t_img *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_hook(img->win, 17, 0, minirt_close, &scene);
	mlx_key_hook(img->win, minirt_key, NULL);
	mlx_loop(img->mlx);
}
