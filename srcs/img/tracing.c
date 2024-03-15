/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:45:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/15 19:35:49 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static t_color	get_color(void *obj, t_objtype type)
{
	t_color	color;

	ft_bzero(&color, sizeof(t_color));
	if (type == SPHERE)
		color = ((t_sphere *)obj)->color;
	else if (type == PLANE)
		color = ((t_plane *)obj)->color;
	else if (type == CYLINDER)
		color = ((t_cylinder *)obj)->color;
	return (color);
}

bool	isshaded(t_intersection *inter, t_light light, t_scene *scene)
{
	t_ray			shadowray;
	t_intersection	*shadedpoint;
	double			dlight;
	double			dobj;

	shadowray.origin = inter->coord;
	shadowray.direction = vector_sub(light.origin, shadowray.origin);
	dlight = norm(shadowray.direction) - EPSILON;
	shadowray.direction = normalize(shadowray.direction);
	shadedpoint = find_nearest_object(shadowray, scene);
	if (shadedpoint != NULL)
	{
		dobj = norm(vector_sub(shadedpoint->coord, shadowray.origin));
		if (dobj < dlight)
			return (true);
	}
	return (false);
}

t_color	raytracer(t_ray ray, t_scene *scene)
{
	t_intersection	*inter;
	t_color			color;
	t_light			*light;

	ft_bzero(&color, sizeof(t_color));
	inter = find_nearest_object(ray, scene);
	if (inter == NULL)
		return (color);
	color = get_color(inter->objptr, inter->type);
	while (light != NULL)
	{
		if (!isshaded(inter, *light, scene))
			color = color_product(color,
					color_scalar(light->color, light->brightness));
	}
	return (color);
}

t_color	whatcolorisit(t_ray ray, t_scene *scene)
{
	t_color	color;

	color = raytracer(ray, scene);
	color = color_product(color, scene->amblight.color);
	return (color);
}
