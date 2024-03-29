/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:28 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/21 23:58:57 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

static void	parse_sphere(char **split, t_objlist **head)
{
	t_sphere	*sphere;
	char		*endptr;
	size_t		i;

	if (arrlen(split) != 4)
		minirt_exit("Invalid sphere line", EXIT_FAILURE);
	sphere = xmalloc(sizeof(t_sphere));
	sphere->center.x = ft_strtod(split[1], &endptr);
	sphere->center.y = ft_strtod(endptr + 1, &endptr);
	sphere->center.z = ft_strtod(endptr + 1, &endptr);
	sphere->radius = ft_strtod(split[2], &endptr) * 0.5;
	sphere->color.r = ft_atoi(split[3]);
	i = 0;
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	sphere->color.g = ft_atoi(split[3] + ++i);
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	sphere->color.b = ft_atoi(split[3] + ++i);
	objlist_add(head, sphere, SPHERE);
}

static void	parse_plane(char **split, t_objlist **head)
{
	t_plane	*plane;
	char	*endptr;
	size_t	i;

	if (arrlen(split) != 4)
		minirt_exit("Invalid plane line", EXIT_FAILURE);
	plane = xmalloc(sizeof(t_plane));
	plane->point.x = ft_strtod(split[1], &endptr);
	plane->point.y = ft_strtod(endptr + 1, &endptr);
	plane->point.z = ft_strtod(endptr + 1, &endptr);
	plane->normal.x = ft_strtod(split[2], &endptr);
	plane->normal.y = ft_strtod(endptr + 1, &endptr);
	plane->normal.z = ft_strtod(endptr + 1, &endptr);
	plane->color.r = ft_atoi(split[3]);
	i = 0;
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	plane->color.g = ft_atoi(split[3] + ++i);
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	plane->color.b = ft_atoi(split[3] + ++i);
	plane->normal = normalize(plane->normal);
	objlist_add(head, plane, PLANE);
}

static void	parse_cylinder(char **split, t_objlist **head)
{
	t_cylinder	*cylinder;
	char		*endptr;
	size_t		i;

	if (arrlen(split) != 6)
		minirt_exit("Invalid cylinder line", EXIT_FAILURE);
	cylinder = xmalloc(sizeof(t_cylinder));
	cylinder->origin.x = ft_strtod(split[1], &endptr);
	cylinder->origin.y = ft_strtod(endptr + 1, &endptr);
	cylinder->origin.z = ft_strtod(endptr + 1, &endptr);
	cylinder->normal.x = ft_strtod(split[2], &endptr);
	cylinder->normal.y = ft_strtod(endptr + 1, &endptr);
	cylinder->normal.z = ft_strtod(endptr + 1, &endptr);
	cylinder->radius = ft_strtod(split[3], &endptr) * 0.5;
	cylinder->height = ft_strtod(split[4], &endptr);
	cylinder->color.r = ft_atoi(split[5]);
	i = 0;
	while (ft_isdigit(split[5][i]) == 1)
		i++;
	cylinder->color.g = ft_atoi(split[5] + ++i);
	while (ft_isdigit(split[5][i]) == 1)
		i++;
	cylinder->color.b = ft_atoi(split[5] + ++i);
	cylinder->normal = normalize(cylinder->normal);
	objlist_add(head, cylinder, CYLINDER);
}

static void	parse_line(char **split, t_scene *scene, size_t i)
{
	if (split[0] == NULL || split[0][0] == '\n')
	{
		free_split(split);
		return ;
	}
	if (split[arrlen(split) - 1][0] == '\n')
	{
		free(split[arrlen(split) - 1]);
		split[arrlen(split) - 1] = NULL;
	}
	if (ft_strcmp(split[0], "sp") == 0)
		parse_sphere(split, &scene->objects);
	else if (ft_strcmp(split[0], "pl") == 0)
		parse_plane(split, &scene->objects);
	else if (ft_strcmp(split[0], "cy") == 0)
		parse_cylinder(split, &scene->objects);
	else if (ft_strcmp(split[0], "A") == 0)
		parse_amblight(split, &scene->amblight);
	else if (ft_strcmp(split[0], "C") == 0)
		parse_camera(split, &scene->camera);
	else if (ft_strcmp(split[0], "L") == 0)
		parse_light(split, &scene->objects);
	else
		minirt_lineerror("Undefined identifier", i);
	free_split(split);
}

void	parse_scene(const char *filename, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**split;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		minirt_exit("Failed to open file", EXIT_FAILURE);
	i = 1;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		if (split == NULL)
			minirt_exit("malloc failed", EXIT_FAILURE);
		checkbadinput(false, split[0]);
		parse_line(split, scene, i);
		free(line);
		i++;
	}
	checkbadinput(true, NULL);
	range_check(*scene);
	close(fd);
}
