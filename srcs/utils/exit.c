/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:59:45 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/11 23:35:38 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	minirt_exit(const char	*message, const int status)
{
	if (message != NULL)
		ft_dprintf(2, "Error\n%s\n", message);
	exit(status);
}
