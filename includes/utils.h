/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:01:04 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/18 16:50:15 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "typedefs.h"
# include "libft.h"

void				free_split(char **split);
void				minirt_exit(const char	*message, const int status);
unsigned int		color_to_uint(t_color color);
t_color				color_product(t_color c1, t_color c2);
t_color				color_sum(t_color c1, t_color c2);
t_color				color_scalar(t_color c, double scalar);

#endif
