/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:28 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 18:23:25 by misargsy         ###   ########.fr       */
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
	sphere->diameter = ft_strtod(split[2], &endptr);
	sphere->color.r = ft_atoi(split[3]);
	i = 0;
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	sphere->color.g = ft_atoi(split[3] + i + 1);
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	sphere->color.b = ft_atoi(split[3] + i + 1);
	objlist_add(head, sphere);
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
	plane->color.g = ft_atoi(split[3] + i + 1);
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	plane->color.b = ft_atoi(split[3] + i + 1);
	objlist_add(head, plane);
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
	cylinder->diameter = ft_strtod(split[3], &endptr);
	cylinder->height = ft_strtod(split[4], &endptr);
	cylinder->color.r = ft_atoi(split[5]);
	i = 0;
	while (ft_isdigit(split[5][i]) == 1)
		i++;
	cylinder->color.g = ft_atoi(split[5] + i + 1);
	while (ft_isdigit(split[5][i]) == 1)
		i++;
	cylinder->color.b = ft_atoi(split[5] + i + 1);
	objlist_add(head, cylinder);
}

static void	parse_line(char *line, t_objlist **head)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL)
		minirt_exit("malloc failed", EXIT_FAILURE);
	if (ft_strcmp(split[0], "sp") == 0)
		parse_sphere(split, head);
	else if (ft_strcmp(split[0], "pl") == 0)
		parse_plane(split, head);
	else if (ft_strcmp(split[0], "cy") == 0)
		parse_cylinder(split, head);
	else if (ft_strcmp(split[0], "A") == 0)
		parse_amblight(split, head);
	else if (ft_strcmp(split[0], "C") == 0)
		parse_camera(split, head);
	else if (ft_strcmp(split[0], "L") == 0)
		parse_light(split, head);
	else
	{
		free_split(split);
		minirt_exit("Invalid line", EXIT_FAILURE);
	}
	free_split(split);
}

void	parse_scene(const char *filename, t_objlist **head)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		minirt_exit("Failed to open file", EXIT_FAILURE);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		parse_line(line, head);
		free(line);
	}
	close(fd);
}
