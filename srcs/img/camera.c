/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:25:06 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/18 15:24:18 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

void	init_camera(t_camera *camera)
{
	double	dist;

	if (fabs(camera->origin.x) < EPS
		&& fabs(camera->origin.y) > EPS && fabs(camera->origin.z) < EPS)
	{
		camera->ex = make_vector(1, 0, 0);
		camera->ey = make_vector(0, 0, -1);
		if (camera->origin.y > 0)
		{
			camera->ex.x *= -1;
			camera->ey.z *= -1;
		}
		return ;
	}
	dist = WIDTH / (2.0 * tan(deg_to_rad(camera->fov) * 0.5));
	camera->to_center = vector_mult(camera->direction, dist);
	camera->ex.x = camera->to_center.z
		/ sqrt(camera->to_center.x * camera->to_center.x
			+ camera->to_center.z * camera->to_center.z);
	camera->ex.y = 0;
	camera->ex.z = -camera->to_center.x
		/ sqrt(camera->to_center.x * camera->to_center.x
			+ camera->to_center.z * camera->to_center.z);
	camera->ex = normalize(camera->ex);
	camera->ey = normalize(cross(camera->ex, camera->to_center));
}
