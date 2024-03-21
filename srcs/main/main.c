/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:10 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/22 01:02:14 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"
#include "render.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		minirt_exit("Invalid arguments", EXIT_FAILURE);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		minirt_exit("Invalid file extension", EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	parse_scene(argv[1], &scene);
	render(&scene);
	minirt_close(&scene);
}
