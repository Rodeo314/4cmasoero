/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:13 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 17:02:03 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

static unsigned long long	printf_llabs(long long value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	internal_printf_get_string_for_d(t_ap_ref *apr, t_printf *specifier)
{
	char		*end;
	long long	llv;

	llv = va_arg(apr->ap, int);
	end = specifier->sr_buff + sizeof(specifier->sr_buff);
	specifier->s_rep_start = ft_u2a(printf_llabs(llv), end, "0123456789", 10);
	if (llv < 0)
		*--specifier->s_rep_start = '-';
	specifier->s_rep_length = ft_strlen(specifier->s_rep_start);
}

// XXX: handle alternate form properly later
void	internal_printf_get_string_for_u(t_ap_ref *apr, t_printf *specifier)
{
	char				*end;
	unsigned long long	ullv;

	if (specifier->va_arg_ctype == 'p')
		ullv = va_arg(apr->ap, uintptr_t);
	else
		ullv = va_arg(apr->ap, unsigned int);
	end = specifier->sr_buff + sizeof(specifier->sr_buff);
	if (specifier->va_arg_ctype == 'u')
		specifier->s_rep_start = ft_u2a(ullv, end, "0123456789", 10);
	else if (specifier->va_arg_ctype == 'X')
		specifier->s_rep_start = ft_u2a(ullv, end, "0123456789ABCDEF", 16);
	else
		specifier->s_rep_start = ft_u2a(ullv, end, "0123456789abcdef", 16);
	if (specifier->va_arg_ctype == 'p')
	{
		*--specifier->s_rep_start = 'x';
		*--specifier->s_rep_start = '0';
	}
	specifier->s_rep_length = ft_strlen(specifier->s_rep_start);
}
