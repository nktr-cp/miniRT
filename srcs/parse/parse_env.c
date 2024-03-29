/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:44 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/21 23:57:42 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

void	parse_amblight(char **split, t_amblight *amblight)

{
	char		*endptr;
	size_t		i;

	if (arrlen(split) != 3)
		minirt_exit("Invalid ambient light line", EXIT_FAILURE);
	amblight->ratio = ft_strtod(split[1], &endptr);
	amblight->color.r = ft_atoi(split[2]);
	i = 0;
	while (ft_isdigit(split[2][i]) == 1)
		i++;
	amblight->color.g = ft_atoi(split[2] + ++i);
	while (ft_isdigit(split[2][i]) == 1)
		i++;
	amblight->color.b = ft_atoi(split[2] + ++i);
}

void	parse_camera(char **split, t_camera *camera)
{
	char		*endptr;

	if (arrlen(split) != 4)
		minirt_exit("Invalid camera line", EXIT_FAILURE);
	camera->origin.x = ft_strtod(split[1], &endptr);
	camera->origin.y = ft_strtod(endptr + 1, &endptr);
	camera->origin.z = ft_strtod(endptr + 1, &endptr);
	camera->direction.x = ft_strtod(split[2], &endptr);
	camera->direction.y = ft_strtod(endptr + 1, &endptr);
	camera->direction.z = ft_strtod(endptr + 1, &endptr);
	camera->fov = ft_strtod(split[3], &endptr);
	camera->direction = normalize(camera->direction);
}

void	parse_light(char **split, t_objlist **head)
{
	t_light		*light;
	char		*endptr;
	size_t		i;

	if (arrlen(split) != 4)
		minirt_exit("Invalid light line", EXIT_FAILURE);
	light = xmalloc(sizeof(t_light));
	light->origin.x = ft_strtod(split[1], &endptr);
	light->origin.y = ft_strtod(endptr + 1, &endptr);
	light->origin.z = ft_strtod(endptr + 1, &endptr);
	light->brightness = ft_strtod(split[2], &endptr);
	light->color.r = ft_atoi(split[3]);
	i = 0;
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	light->color.g = ft_atoi(split[3] + ++i);
	while (ft_isdigit(split[3][i]) == 1)
		i++;
	light->color.b = ft_atoi(split[3] + ++i);
	objlist_add(head, light, LIGHT);
}
