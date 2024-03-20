/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:45:31 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/21 04:10:35 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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

bool	isshaded(t_intersection inter, t_light light, t_scene *scene)
{
	t_ray			shadowray;
	t_intersection	shadingobject;
	double			dlight;
	double			dobj;

	shadowray.origin = vector_add(inter.coord, vector_mult(inter.normal, EPS));
	shadowray.direction = normalize(vector_sub(light.origin, shadowray.origin));
	dlight = norm(vector_sub(light.origin, shadowray.origin));
	shadingobject = find_nearest_object(shadowray, scene);
	if (shadingobject.dist != INF)
	{
		dobj = norm(vector_sub(shadingobject.coord, shadowray.origin));
		if (dobj < dlight)
			return (true);
	}
	return (false);
}

static t_light	*get_next_light(t_objlist *lst)
{
	static size_t	i = 0;
	size_t			n;

	n = 0;
	while (n < i)
	{
		lst = lst->next;
		n++;
	}
	while (lst != NULL && lst->type != LIGHT)
	{
		lst = lst->next;
		n++;
	}
	if (lst == NULL)
	{
		i = 0;
		return (NULL);
	}
	else
	{
		i = n + 1;
		return ((t_light *)lst->obj);
	}
}

static t_color	raytracer(t_ray ray, t_scene *scene)
{
	t_intersection	inter;
	t_color			color;
	t_light			*light;
	double			angle;
	t_color			objcolor;

	ft_bzero(&color, sizeof(t_color));
	inter = find_nearest_object(ray, scene);
	if (inter.dist == INF)
		return (color);
	objcolor = get_color(inter.objptr, inter.type);
	color = (t_color){0, 0, 0};
	while (true)
	{
		light = get_next_light(scene->objects);
		if (light == NULL)
			break ;
		angle = fmax(dot(inter.normal,
					normalize(vector_sub(light->origin, inter.coord))), 0);
		if (!isshaded(inter, *light, scene))
			color = color_sum(color,
					get_diffused_color(angle, objcolor, light));
	}
	color = color_sum(color, get_ambient_color(objcolor, &scene->amblight));
	return (color);
}

t_color	whatcolorisit(t_ray ray, t_scene *scene)
{
	t_color	color;

	color = raytracer(ray, scene);
	return (color);
}
