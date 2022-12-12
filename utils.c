/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:02:20 by twalker           #+#    #+#             */
/*   Updated: 2022/12/02 12:58:24 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdint.h>
#include <unistd.h>

char	*ft_u2a(
	unsigned long long value,
	char *ret, char *digits,
	unsigned int radix)
{
	*--ret = '\0';
	while (value >= radix)
	{
		*--ret = digits[value % radix];
		value /= radix;
	}
	*--ret = digits[value];
	return (ret);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		b;

	a = s;
	b = c;
	while (n--)
		if (*a++ == b)
			return ((void *)--a);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	return (ft_strnlen(s, SIZE_MAX));
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*end;

	end = ft_memchr(s, '\0', maxlen);
	if (!end)
		return (maxlen);
	return (end - s);
}

ssize_t	ft_write(int fildes, const void *buf, size_t nbyte)
{
	return (write(fildes, buf, nbyte));
}
