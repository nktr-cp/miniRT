/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:32:19 by misargsy          #+#    #+#             */
/*   Updated: 2023/11/19 22:20:20 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	d;

	d = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		d += 2;
		n /= -10;
	}
	while (n > 0)
	{
		d++;
		n /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		d;

	d = numlen(n);
	str = (char *)malloc(sizeof(char) * (d + 1));
	if (str == NULL)
		return (NULL);
	str[d] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		str[d-- - 1] = -(n % 10) + '0';
		n /= -10;
	}
	while (n > 0)
	{
		str[d-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
