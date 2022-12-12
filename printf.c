/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:39:19 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 15:53:52 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"

#include <stdarg.h>
#include <unistd.h>

static int	vdprintf_start2end(
	int fd, const char *start, const char *end, int *count)
{
	int	ret;

	ret = 0;
	if (start < end && *start)
		ret = ft_write(fd, start, end - start);
	if (ret < 0)
		return (-1);
	*count += ret;
	return (0);
}

int	internal_vdprintf(int fd, const char *format, t_ap_ref *apr)
{
	const char	*start;
	int			count;

	count = 0;
	start = format;
	while (*format)
	{
		if (*format == '%')
		{
			if (vdprintf_start2end(fd, start, format, &count))
				return (-1);
			start = internal_printf_specifier(fd, ++format, apr, &count);
			if (!start)
				return (-1);
			format = start;
			continue ;
		}
		format++;
	}
	if (vdprintf_start2end(fd, start, format, &count))
		return (-1);
	return (count);
}

/*//
static int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_ap_ref	apr;
	int			ret;

	va_copy(apr.ap, ap);
	ret = internal_vdprintf(fd, format, &apr);
	va_end(apr.ap);
	return (ret);
}
//*/

/*//
int	ft_dprintf(int fd, const char *format, ...)
{
	t_ap_ref	apr;
	int			ret;

	va_start(apr.ap, format);
	ret = internal_vdprintf(fd, format, &apr);
	va_end(apr.ap);
	return (ret);
}
//*/

int	ft_printf(const char *format, ...)
{
	t_ap_ref	apr;
	int			ret;

	va_start(apr.ap, format);
	ret = internal_vdprintf(STDOUT_FILENO, format, &apr);
	va_end(apr.ap);
	return (ret);
}
