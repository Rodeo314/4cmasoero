/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:42:48 by twalker           #+#    #+#             */
/*   Updated: 2022/12/12 17:02:03 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include <stdarg.h>
# include <stdbool.h>

typedef struct s_ap_ref	t_ap_ref;
typedef struct s_printf	t_printf;

struct s_ap_ref
{
	va_list	ap;
};

struct s_printf
{
	char	va_arg_ctype;
	bool	left_justify;
	bool	sign_precede;
	bool	prependspace;
	bool	alternatform;
	bool	zero_padding;
	int		minimumwidth;
	bool	argumntwidth;
	int		hasprecision;
	bool	argprecision;
	char	*s_rep_start;
	int		s_rep_length;
	char	sr_buff[128];
};

void		internal_printf_get_string_for_c(t_ap_ref *apr,
				t_printf *specifier);
void		internal_printf_get_string_for_d(t_ap_ref *apr,
				t_printf *specifier);
void		internal_printf_get_string_for_s(t_ap_ref *apr,
				t_printf *specifier);
void		internal_printf_get_string_for_u(t_ap_ref *apr,
				t_printf *specifier);
int			internal_printf_get_string_4_arg(t_ap_ref *apr,
				t_printf *specifier);

int			internal_vdprintf(int fd, const char *format, t_ap_ref *apr);

const char	*internal_printf_specifier(
				int fd, const char *format, t_ap_ref *apr, int *count);
const char	*internal_printf_specifier_parse(
				const char *format, t_printf *specifier);
int			internal_printf_specifier_print(
				int fd, t_ap_ref *apr, t_printf *specifier);

#endif
