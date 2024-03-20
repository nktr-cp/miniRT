/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:24:27 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/21 03:47:06 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_color	get_diffused_color(double cosine, t_color objectcolor, t_light *light)
{
	t_color	diffused;

	diffused = color_scalar(color_product(objectcolor, light->color),
			cosine * light->brightness);
	return (diffused);
}

t_color	get_ambient_color(t_color objectcolor, t_amblight *light)
{
	t_color	ambient;

	ambient = color_scalar(light->color, light->ratio);
	ambient = color_product(objectcolor, ambient);
	return (ambient);
}
