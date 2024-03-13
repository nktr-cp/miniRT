/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:54:10 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 18:23:45 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_objlist	*head;

	if (argc != 2)
		minirt_exit("Invalid arguments", EXIT_FAILURE);
	head = NULL;
	parse_scene(argv[1], &head);
	objlist_clear(&head);
	minirt_exit(NULL, EXIT_SUCCESS);
}

// __attribute__((destructor))
// static void	leaks(void)
// {
// 	system("leaks -q miniRT");
// }
