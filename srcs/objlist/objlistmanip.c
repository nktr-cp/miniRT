/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objlistmanip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:51:56 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/11 23:37:03 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"
#include "libft.h"

static t_objlist	*objlist_new(void *obj)
{
	t_objlist	*new;

	new = xmalloc(sizeof(t_objlist));
	new->obj = obj;
	new->next = NULL;
	return (new);
}

void	objlist_add(t_objlist **list, void *obj)
{
	t_objlist	*new;
	t_objlist	*tmp;

	new = objlist_new(obj);
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}