/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:20:05 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static int	uint_prefix(const t_format format, size_t len)
{
	int	chars_printed;
	int	prefix_padding;

	chars_printed = 0;
	if (has_flag(format.flags, F_MINUS)
		|| (has_flag(format.flags, F_ZERO) && !has_flag(format.flags, F_PREC)))
		prefix_padding = 0;
	else if (has_flag(format.flags, F_PREC) && len < format.prec)
		prefix_padding = format.width - format.prec;
	else
		prefix_padding = format.width - len;
	while (prefix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}

static int	uint_body(const t_format format, unsigned int num, size_t len)
{
	int	chars_printed;
	int	zero_padding;

	chars_printed = 0;
	zero_padding = 0;
	if (has_flag(format.flags, F_ZERO))
		zero_padding = format.width - len;
	if (has_flag(format.flags, F_PREC))
		zero_padding = format.prec - len;
	while (zero_padding-- > 0)
		chars_printed += write(format.fd, "0", 1);
	if (num == 0 && has_flag(format.flags, F_PREC) && format.prec == 0)
		return (chars_printed);
	putnbr_unsigned(num, 10U, DECIMAL, format.fd);
	chars_printed += len;
	return (chars_printed);
}

int	print_uint(const t_format format, const unsigned int num)
{
	const size_t	len = uintlen(num, 10);
	int				chars_printed;
	int				suffix_padding;

	chars_printed = uint_prefix(format, len);
	chars_printed += uint_body(format, num, len);
	suffix_padding = format.width - chars_printed;
	while (suffix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}
