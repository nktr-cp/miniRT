/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 07:19:11 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:52 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

int	print_char(const t_format format, const char c)
{
	int	chars_printed;
	int	width;
	int	suffix_padding;

	chars_printed = 0;
	if (has_flag(format.flags, F_MINUS))
		width = 0;
	else
		width = format.width - 1;
	while (width-- > 0)
		chars_printed += write(format.fd, " ", 1);
	chars_printed += write(format.fd, &c, 1);
	suffix_padding = format.width - chars_printed;
	while (suffix_padding-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}

int	print_string(const t_format format, const char *str)
{
	int		chars_printed;
	int		padding_width;
	size_t	bytes_to_write;

	chars_printed = 0;
	if (str == NULL)
		bytes_to_write = ft_strlen(NULL_LITERAL);
	else
		bytes_to_write = ft_strlen(str);
	if (has_flag(format.flags, F_PREC) && format.prec < bytes_to_write)
		bytes_to_write = format.prec;
	if (has_flag(format.flags, F_MINUS))
		padding_width = 0;
	else
		padding_width = format.width - bytes_to_write;
	while (padding_width-- > 0)
		chars_printed += write(format.fd, " ", 1);
	if (str == NULL)
		chars_printed += write(format.fd, NULL_LITERAL, bytes_to_write);
	else
		chars_printed += write(format.fd, str, bytes_to_write);
	padding_width = format.width - chars_printed;
	while (padding_width-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}

int	print_percent(const t_format format)
{
	int	chars_printed;
	int	padding_width;

	chars_printed = 0;
	if (has_flag(format.flags, F_MINUS))
		padding_width = 0;
	else
		padding_width = format.width - 1;
	while (padding_width-- > 0)
		chars_printed += write(format.fd, " ", 1);
	chars_printed += write(format.fd, "%", 1);
	padding_width = format.width - chars_printed;
	while (padding_width-- > 0)
		chars_printed += write(format.fd, " ", 1);
	return (chars_printed);
}
