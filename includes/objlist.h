/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:56:41 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 17:55:17 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJLIST_H
# define OBJLIST_H

# include "typedefs.h"
# include "libft.h"

typedef struct s_objlist	t_objlist;

void	objlist_add(t_objlist **list, void *obj);
void	objlist_clear(t_objlist **list);

#endif
