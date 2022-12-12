/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:39:51 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 17:02:03 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"

#include <stdarg.h>

// (potentially) future specifiers
static int	get_string_4_arg_others(t_ap_ref *apr, t_printf *specifier)
{
	(void)apr;
	(void)specifier;
	return (-1);
}

int	internal_printf_get_string_4_arg(t_ap_ref *apr, t_printf *specifier)
{
	if (specifier->va_arg_ctype == '%' || specifier->va_arg_ctype == 'c')
		internal_printf_get_string_for_c(apr, specifier);
	else if (specifier->va_arg_ctype == 'd')
		internal_printf_get_string_for_d(apr, specifier);
	else if (specifier->va_arg_ctype == 'i')
		internal_printf_get_string_for_d(apr, specifier);
	else if (specifier->va_arg_ctype == 'p')
		internal_printf_get_string_for_u(apr, specifier);
	else if (specifier->va_arg_ctype == 's')
		internal_printf_get_string_for_s(apr, specifier);
	else if (specifier->va_arg_ctype == 'u')
		internal_printf_get_string_for_u(apr, specifier);
	else if (specifier->va_arg_ctype == 'x')
		internal_printf_get_string_for_u(apr, specifier);
	else if (specifier->va_arg_ctype == 'X')
		internal_printf_get_string_for_u(apr, specifier);
	else
		return (get_string_4_arg_others(apr, specifier));
	return (0);
}

int	internal_printf_specifier_print(int fd, t_ap_ref *apr, t_printf *specifier)
{
	if (internal_printf_get_string_4_arg(apr, specifier))
		return (-1);
	return (ft_write(fd, specifier->s_rep_start, specifier->s_rep_length));
}
