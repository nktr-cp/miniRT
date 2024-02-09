/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 03:00:42 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void	get_flags(const char **format, t_format *data)
{
	while (ft_strchr(FLAGS, **format))
	{
		if (**format == '-')
			data->flags |= F_MINUS;
		else if (**format == '0')
			data->flags |= F_ZERO;
		else if (**format == '#')
			data->flags |= F_HASH;
		else if (**format == ' ')
			data->flags |= F_SPACE;
		else if (**format == '+')
			data->flags |= F_PLUS;
		(*format)++;
	}
}

static void	get_width(const char **format, t_format *data)
{
	if (ft_isdigit(**format))
	{
		data->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

static void	get_prec(const char **format, t_format *data)
{
	if (**format == '.')
	{
		data->flags |= F_PREC;
		(*format)++;
		if (ft_isdigit(**format))
		{
			data->prec = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
}

void	get_format(const char **format, const int fd, t_format *data)
{
	ft_bzero(data, sizeof(t_format));
	data->fd = fd;
	get_flags(format, data);
	get_width(format, data);
	get_prec(format, data);
}
