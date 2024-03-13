/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:29 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 17:17:24 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

# include "libft.h"
# include "typedefs.h"
# include "utils.h"

# include <fcntl.h>
# include <stdbool.h>

void	parse_amblight(char **split, t_objlist **head);
void	parse_camera(char **split, t_objlist **head);
void	parse_light(char **split, t_objlist **head);

double	ft_strtod(const char *str, char **endptr);
size_t	arrlen(char **arr);

#endif
