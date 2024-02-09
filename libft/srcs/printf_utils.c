/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:49:49 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

bool	has_flag(const int flag, const int flagmacro)
{
	return ((flag & flagmacro) == flagmacro);
}

void	putnbr_unsigned(
	const uint64_t num,
	const unsigned int base,
	const char *basestr,
	const int fd)
{
	if (num >= base)
		putnbr_unsigned(num / base, base, basestr, fd);
	ft_putchar_fd(basestr[num % base], fd);
}

size_t	intlen(int64_t num, const int base)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		num /= -base;
		len++;
	}
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

size_t	uintlen(uint64_t num, const int base)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}
