/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:10 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/14 17:35:59 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

#include <stdio.h>
static void	print_objlist(t_objlist *list)
{
	t_objlist	*tmp;
	t_objtype	type;

	tmp = list;
	while (tmp)
	{
		type = tmp->type;
		if (type == SPHERE)
		{
			t_sphere	*sphere = (t_sphere *)tmp->obj;
			printf("Sphere\n");
			printf("center: %f %f %f, diameter: %f, color: %d %d %d\n",
				sphere->center.x, sphere->center.y, sphere->center.z,
				sphere->diameter, sphere->color.r, sphere->color.g, sphere->color.b);
		}
		if (type == LIGHT)
		{
			t_light	*light = (t_light *)tmp->obj;
			printf("Light\n");
			printf("origin: %f %f %f, brightness: %f, color: %d %d %d\n",
				light->origin.x, light->origin.y, light->origin.z,
				light->brightness, light->color.r, light->color.g, light->color.b);
		}
		if (type == PLANE)
		{
			t_plane	*plane = (t_plane *)tmp->obj;
			printf("Plane\n");
			printf("point: %f %f %f, normal: %f %f %f, color: %d %d %d\n",
				plane->point.x, plane->point.y, plane->point.z,
				plane->normal.x, plane->normal.y, plane->normal.z,
				plane->color.r, plane->color.g, plane->color.b);
		}
		if (type == CYLINDER)
		{
			t_cylinder	*cylinder = (t_cylinder *)tmp->obj;
			printf("Cylinder\n");
			printf("origin: %f %f %f, normal: %f %f %f, diameter: %f, height: %f, color: %d %d %d\n",
				cylinder->origin.x, cylinder->origin.y, cylinder->origin.z,
				cylinder->normal.x, cylinder->normal.y, cylinder->normal.z,
				cylinder->diameter, cylinder->height,
				cylinder->color.r, cylinder->color.g, cylinder->color.b);
		}
		tmp = tmp->next;
	}
}

static void	print_amblight(t_amblight amblight)
{
	printf("Ambient light\n");
	printf("ratio: %f, color: %d %d %d\n",
		amblight.ratio, amblight.color.r, amblight.color.g, amblight.color.b);
}

static void	print_camera(t_camera camera)
{
	printf("Camera\n");
	printf("origin: %f %f %f, direction: %f %f %f, fov: %f\n",
		camera.origin.x, camera.origin.y, camera.origin.z,
		camera.direction.x, camera.direction.y, camera.direction.z,
		camera.fov);

}

static void	check(t_scene scene)
{
	print_camera(scene.camera);
	print_amblight(scene.amblight);
	print_objlist(scene.objects);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		minirt_exit("Invalid arguments", EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	parse_scene(argv[1], &scene);
	check(scene);
	objlist_clear(&scene.objects);
	minirt_exit(NULL, EXIT_SUCCESS);
}

// __attribute__((destructor))
// static void	leaks(void)
// {
// 	system("leaks -q miniRT");
// }
