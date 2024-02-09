/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:25:18 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:29:53 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>

# define HEX_LC "0123456789abcdefx"
# define HEX_UC "0123456789ABCDEFX"
# define DECIMAL "0123456789"
# define FLAGS "-0# +"
# define CONVERSIONS "cspdiuxX%"
# define NULL_LITERAL "(null)"
# define HEX_PREFIX_LEN 2

# define F_PLUS		0b000001
# define F_MINUS	0b000010
# define F_ZERO		0b000100
# define F_SPACE	0b001000
# define F_PREC		0b010000
# define F_HASH		0b100000

typedef struct s_format
{
	int		fd;
	int		flags;
	size_t	prec;
	size_t	width;
}	t_format;

// printf_get_format.c
void	get_format(const char **format, const int fd, t_format *data);

// printf_*.c
int		print_char(const t_format format, const char c);
int		print_string(const t_format format, const char *str);
int		print_pointer(t_format format, const void *ptr);
int		print_int(const t_format format, const int num);
int		print_uint(const t_format format, const unsigned int num);
int		print_hex(
			t_format format,
			const unsigned int num,
			const char *base);
int		print_percent(const t_format format);

// printf_utils.c
bool	has_flag(const int flag, const int flagmacro);
void	putnbr_unsigned(
			const uint64_t num,
			const unsigned int base,
			const char *basestr,
			const int fd);
size_t	intlen(int64_t num, const int base);
size_t	uintlen(uint64_t num, const int base);

#endif
