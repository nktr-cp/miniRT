/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:25:06 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/14 18:57:45 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

// 計算式など: https://jun-networks.hatenablog.com/entry/2021/04/02/043216#%E5%AE%9F%E8%A3%85
void	init_camera(t_camera *camera)
{
	double	dist;

	dist = WIDTH / (2.0 * tan(deg_to_rad(camera->fov) * 0.5));
	camera->to_center = vector_mult(camera->direction,dist);
	camera->ex.x = camera->to_center.z / sqrt(camera->to_center.x * camera->to_center.x + camera->to_center.z * camera->to_center.z);
	camera->ex.y = 0;
	camera->ex.z = -camera->to_center.x / sqrt(camera->to_center.x * camera->to_center.x + camera->to_center.z * camera->to_center.z);
	camera->ex = normalize(camera->ex);
	// camera->ey = normalize(cross(camera->to_center, camera->ex));
	camera->ey = normalize(cross(camera->ex, camera->to_center));

	// TODO
	// edge case?
}
