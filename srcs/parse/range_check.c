/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:04:12 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/14 18:30:33 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

static bool	colorisinrange(t_color color)
{
	if (color.r < 0 || color.r > 255)
		return (false);
	if (color.g < 0 || color.g > 255)
		return (false);
	if (color.b < 0 || color.b > 255)
		return (false);
	return (true);
}

static bool	vectorisinrange(t_vector vector)
{
	if (vector.x < -1 || vector.x > 1)
		return (false);
	if (vector.y < -1 || vector.y > 1)
		return (false);
	if (vector.z < -1 || vector.z > 1)
		return (false);
	return (true);
}

static bool	ratioisinrange(double ratio)
{
	return (ratio >= 0 && ratio <= 1);
}

static bool	objconfisinrange(t_objlist *head)
{
	bool	isinrange;

	while (head != NULL)
	{
		if (head->type == SPHERE)
			isinrange = colorisinrange(((t_sphere *)head->obj)->color);
		if (head->type == LIGHT)
			isinrange = (colorisinrange(((t_light *)head->obj)->color)
					&& ratioisinrange(((t_light *)head->obj)->brightness));
		if (head->type == PLANE)
			isinrange = (vectorisinrange(((t_plane *)head->obj)->normal)
					&& colorisinrange(((t_plane *)head->obj)->color));
		if (head->type == CYLINDER)
			isinrange = (vectorisinrange(((t_cylinder *)head->obj)->normal)
					&& colorisinrange(((t_cylinder *)head->obj)->color));
		head = head->next;
		if (!isinrange)
			return (false);
	}
	return (true);
}

void	range_check(t_scene scene)
{
	if (scene.amblight.ratio < 0 || scene.amblight.ratio > 1)
		minirt_exit("Ambient light ratio out of range", EXIT_FAILURE);
	if (!colorisinrange(scene.amblight.color))
		minirt_exit("Ambient light color out of range", EXIT_FAILURE);
	if (!vectorisinrange(scene.camera.direction))
		minirt_exit("Camera direction out of range", EXIT_FAILURE);
	if (scene.camera.fov < 0 || scene.camera.fov > 180)
		minirt_exit("Camera FOV out of range", EXIT_FAILURE);
	if (!objconfisinrange(scene.objects))
		minirt_exit("More than one object configuration out of range",
			EXIT_FAILURE);
}
