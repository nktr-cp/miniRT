/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 08:01:54 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static int	hex_prefix(
	const t_format format,
	const size_t len,
	const char *base)
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
	if (has_flag(format.flags, F_HASH))
		prefix_padding -= HEX_PREFIX_LEN;
	while (prefix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	if (has_flag(format.flags, F_HASH))
	{
		chars_printed += write(format.fd, "0", 1);
		chars_printed += write(format.fd, &base[16], 1);
	}
	return (chars_printed);
}

static int	hex_body(
	const t_format format,
	const uint64_t num,
	const size_t len,
	const char *base)
{
	int	chars_printed;
	int	zero_padding;

	chars_printed = 0;
	zero_padding = 0;
	if (has_flag(format.flags, F_ZERO))
		zero_padding = format.width - len;
	if (has_flag(format.flags, F_HASH))
		zero_padding -= HEX_PREFIX_LEN;
	if (has_flag(format.flags, F_PREC))
		zero_padding = format.prec - len;
	while (zero_padding-- > 0)
		chars_printed += write(format.fd, "0", 1);
	if (has_flag(format.flags, F_PREC) && format.prec == 0 && num == 0)
		return (chars_printed);
	putnbr_unsigned(num, 16U, base, format.fd);
	chars_printed += len;
	return (chars_printed);
}

int	print_pointer(t_format format, const void *ptr)
{
	const size_t	len = uintlen((uintptr_t)ptr, 16);
	int				chars_printed;
	int				suffix_padding;

	format.flags |= F_HASH;
	format.flags &= ~F_SPACE;
	format.flags &= ~F_PREC;
	format.prec = 0;
	chars_printed = hex_prefix(format, len, HEX_LC);
	chars_printed += hex_body(format, (uintptr_t)ptr, len, HEX_LC);
	suffix_padding = format.width - chars_printed;
	while (suffix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}

int	print_hex(
	t_format format,
	const unsigned int num,
	const char *base)
{
	const size_t	len = uintlen(num, 16);
	int				chars_printed;
	int				suffix_padding;

	if (num == 0)
		format.flags &= ~F_HASH;
	chars_printed = hex_prefix(format, len, base);
	chars_printed += hex_body(format, num, len, base);
	suffix_padding = format.width - chars_printed;
	while (suffix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}
