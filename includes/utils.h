/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:01:04 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 21:17:04 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "typedefs.h"
# include "libft.h"

void	free_split(char **split);
void	minirt_exit(const char	*message, const int status);
int		color_to_int(t_color color);

#endif
