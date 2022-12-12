/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:10 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 17:02:03 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"

#include <stdarg.h>

void	internal_printf_get_string_for_c(t_ap_ref *apr, t_printf *specifier)
{
	if (specifier->va_arg_ctype == 'c')
		*specifier->sr_buff = va_arg(apr->ap, int);
	else
		*specifier->sr_buff = '%';
	specifier->s_rep_start = specifier->sr_buff;
	specifier->s_rep_length = 1;
}

void	internal_printf_get_string_for_s(t_ap_ref *apr, t_printf *specifier)
{
	specifier->s_rep_start = va_arg(apr->ap, char *);
	if (specifier->s_rep_start == NULL)
		specifier->s_rep_start = "(null)";
	specifier->s_rep_length = ft_strlen(specifier->s_rep_start);
	if (specifier->hasprecision >= 0)
		if (specifier->s_rep_length > specifier->hasprecision)
			specifier->s_rep_length = specifier->hasprecision;
}
