/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:29 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/21 23:56:04 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

# include "libft.h"
# include "typedefs.h"
# include "utils.h"
# include "vector.h"

# include <fcntl.h>

void	parse_amblight(char **split, t_amblight *amblight);
void	parse_camera(char **split, t_camera *camera);
void	parse_light(char **split, t_objlist **head);

double	ft_strtod(const char *str, char **endptr);
size_t	arrlen(char **arr);
void	checkbadinput(bool last, char *type);

void	range_check(t_scene scene);

#endif
