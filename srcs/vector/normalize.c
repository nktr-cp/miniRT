/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:25:33 by knishiok          #+#    #+#             */
/*   Updated: 2024/03/13 21:34:51 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	normalize(t_vector v)
{
	t_vector	res;
	double		siz;

	siz = norm(v);
	if (siz == 0)
		return (v);
	res.x = v.x / siz;
	res.y = v.y / siz;
	res.z = v.z / siz;
	return (res);
}
