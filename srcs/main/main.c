/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:10 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/22 00:59:30 by knishiok         ###   ########.fr       */
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
	ft_bzero(&scene, sizeof(t_scene));
	parse_scene(argv[1], &scene);
	render(&scene);
	minirt_close(&scene);
}
