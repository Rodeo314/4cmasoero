/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:41:31 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 17:43:15 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

static const char	*printf_specifier_defaults(
	const char *format, t_printf *specifier)
{
	specifier->left_justify = false;
	specifier->sign_precede = false;
	specifier->prependspace = false;
	specifier->alternatform = false;
	specifier->zero_padding = false;
	specifier->argumntwidth = false;
	specifier->argprecision = false;
	specifier->va_arg_ctype = '\0';
	specifier->minimumwidth = -1;
	specifier->hasprecision = -1;
	return (format);
}

const char	*internal_printf_specifier(
	int fd, const char *format, t_ap_ref *apr, int *count)
{
	t_printf	specifier;
	int			mincount;

	mincount = *count;
	format = printf_specifier_defaults(format, &specifier);
	format = internal_printf_specifier_parse(format, &specifier);
	*count = internal_printf_specifier_print(fd, apr, &specifier) + mincount;
	if (*count < mincount)
		return (NULL);
	return (format);
}
