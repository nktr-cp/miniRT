/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:01:04 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/15 19:34:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "typedefs.h"
# include "libft.h"

void	free_split(char **split);
void	minirt_exit(const char	*message, const int status);
int		color_to_int(t_color color);
t_color	color_product(t_color c1, t_color c2);
t_color	color_sum(t_color c1, t_color c2);
t_color	color_scalar(t_color c, double scalar);

#endif
