/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:19:35 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void	putnbr_without_sign(const int num, const int fd)
{
	if (num < 0)
	{
		if (num <= -10)
			putnbr_without_sign(-(num / 10), fd);
		ft_putchar_fd(-(num % 10) + '0', fd);
	}
	else
	{
		if (num >= 10)
			putnbr_without_sign(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

static int	int_prefix(const t_format format, const int num, const size_t len)
{
	int	chars_printed;
	int	prefix_padding;

	chars_printed = 0;
	prefix_padding = format.width - len;
	if (has_flag(format.flags, F_MINUS)
		|| (has_flag(format.flags, F_ZERO) && !has_flag(format.flags, F_PREC)))
		prefix_padding = 0;
	else if (has_flag(format.flags, F_PREC) && len < format.prec)
		prefix_padding = format.width - format.prec;
	if (num == 0 && has_flag(format.flags, F_PREC)
		&& format.prec == 0 && prefix_padding > 0)
		prefix_padding++;
	if (num < 0 || has_flag(format.flags, F_PLUS)
		|| has_flag(format.flags, F_SPACE))
		prefix_padding--;
	while (prefix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	if (num < 0)
		chars_printed += write(format.fd, "-", 1);
	else if (has_flag(format.flags, F_PLUS))
		chars_printed += write(format.fd, "+", 1);
	else if (has_flag(format.flags, F_SPACE))
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}

static int	int_body(const t_format format, const int num, const size_t len)
{
	int	chars_printed;
	int	zero_padding;

	chars_printed = 0;
	zero_padding = 0;
	if (has_flag(format.flags, F_ZERO))
	{
		zero_padding = format.width - len;
		if (num < 0 || has_flag(format.flags, F_PLUS)
			|| has_flag(format.flags, F_SPACE))
			zero_padding--;
	}
	if (has_flag(format.flags, F_PREC))
		zero_padding = format.prec - len;
	while (zero_padding-- > 0)
		chars_printed += write(format.fd, "0", 1);
	if (num == 0 && has_flag(format.flags, F_PREC) && format.prec == 0)
		return (chars_printed);
	putnbr_without_sign(num, format.fd);
	chars_printed += len;
	return (chars_printed);
}

int	print_int(const t_format format, const int num)
{
	const size_t	len = intlen(num, 10);
	int				chars_printed;
	int				suffix_padding;

	chars_printed = int_prefix(format, num, len);
	chars_printed += int_body(format, num, len);
	suffix_padding = format.width - chars_printed;
	while (suffix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}
