/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:39:04 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 17:37:20 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"

#include <stdarg.h>
#include <stdbool.h>

// note: flags may come in any order, AFAICT
static const char	*printf_specifier_parse_flags(
	const char *format, t_printf *specifier)
{
	while (ft_memchr("-+ #0", *format, 5))
	{
		if (*format == '-')
			specifier->left_justify = true;
		else if (*format == '+')
			specifier->sign_precede = true;
		else if (*format == ' ')
			specifier->prependspace = true;
		else if (*format == '#')
			specifier->alternatform = true;
		else if (*format == '0')
			specifier->zero_padding = true;
		format++;
	}
	return (format);
}

static const char	*printf_specifier_parse_width(
	const char *format, t_printf *specifier)
{
	if (*format == '*' && format++)
	{
		specifier->argumntwidth = true;
		return (format);
	}
	if (ft_isdigit(*format))
	{
		specifier->minimumwidth = ft_atoi(format);
		while (ft_isdigit(*format) && format++)
			continue ;
		return (format);
	}
	return (format);
}

static const char	*printf_specifier_parse_preci(
	const char *format, t_printf *specifier)
{
	if (*format == '.' && format++)
	{
		if (*format == '*' && format++)
		{
			specifier->argprecision = true;
			return (format);
		}
		if (ft_isdigit(*format))
		{
			specifier->hasprecision = ft_atoi(format);
			while (ft_isdigit(*format) && format++)
				continue ;
			return (format);
		}
		specifier->hasprecision = 0;
		return (format);
	}
	return (format);
}

// TODO: future: support length sub-specifier
const char	*internal_printf_specifier_parse(
	const char *format, t_printf *specifier)
{
	format = printf_specifier_parse_flags(format, specifier);
	format = printf_specifier_parse_width(format, specifier);
	format = printf_specifier_parse_preci(format, specifier);
	if (0
		|| *format == 's'
		|| *format == '%' || *format == 'c'
		|| *format == 'd' || *format == 'i'
		|| *format == 'u' || *format == 'p'
		|| *format == 'x' || *format == 'X')
		specifier->va_arg_ctype = *format++;
	return (format);
}
