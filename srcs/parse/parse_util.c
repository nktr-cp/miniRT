/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:47:59 by misargsy          #+#    #+#             */
/*   Updated: 2024/03/13 21:51:36 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

static double	get_whole(const char *str, char **endptr)
{
	double		whole;

	whole = 0;
	while (ft_isdigit(*str) == 1)
	{
		whole = whole * 10 + (*str - '0');
		str++;
	}
	*endptr = (char *)str;
	return (whole);
}

static double	get_decimal(const char *str, char **endptr)
{
	double		decimal;
	double		divider;

	decimal = 0;
	divider = 10;
	while (ft_isdigit(*str) == 1)
	{
		decimal += (*str - '0') / divider;
		divider *= 10;
		str++;
	}
	*endptr = (char *)str;
	return (decimal);
}

double	ft_strtod(const char *str, char **endptr)
{
	double		result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '\0')
	{
		*endptr = (char *)str;
		return (0);
	}
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	result = get_whole(str, endptr);
	if (**endptr == '.')
	{
		(*endptr)++;
		result += get_decimal(*endptr, endptr);
	}
	return (result * sign);
}

size_t	arrlen(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

void	checkbadinput(bool last, char *type)
{
	static bool	camera = false;
	static bool	amblight = false;

	if (last)
	{
		if (!camera)
			minirt_exit("No camera line", EXIT_FAILURE);
	}
	else
	{
		if (ft_strcmp(type, "C") == 0)
		{
			if (camera)
				minirt_exit("Too many camera lines", EXIT_FAILURE);
			camera = true;
		}
		else if (ft_strcmp(type, "A") == 0)
		{
			if (amblight)
				minirt_exit("Too many ambient light lines", EXIT_FAILURE);
			amblight = true;
		}
	}
}
