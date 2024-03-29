/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:14:51 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/21 03:09:37 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	trim_rgb(t_color color)
{
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (color);
}

unsigned int	color_to_uint(t_color color)
{
	return ((unsigned int)(color.r << 16 | color.g << 8 | color.b));
}

t_color	color_product(t_color c1, t_color c2)
{
	t_color	res;

	res.r = c1.r * c2.r;
	res.g = c1.g * c2.g;
	res.b = c1.b * c2.b;
	res.r /= (255);
	res.g /= (255);
	res.b /= (255);
	return (trim_rgb(res));
}

t_color	color_sum(t_color c1, t_color c2)
{
	t_color	res;

	res.r = c1.r + c2.r;
	res.g = c1.g + c2.g;
	res.b = c1.b + c2.b;
	return (trim_rgb(res));
}

t_color	color_scalar(t_color c, double scalar)
{
	t_color	res;

	res.r = c.r * scalar;
	res.g = c.g * scalar;
	res.b = c.b * scalar;
	return (trim_rgb(res));
}
