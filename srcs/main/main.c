/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:10 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 21:55:24 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		minirt_exit("Invalid arguments", EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	parse_scene(argv[1], &scene);
	objlist_clear(&scene.objects);
	minirt_exit(NULL, EXIT_SUCCESS);
}

// __attribute__((destructor))
// static void	leaks(void)
// {
// 	system("leaks -q miniRT");
// }
