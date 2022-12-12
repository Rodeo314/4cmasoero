/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:54:49 by twalker           #+#    #+#             */
/*   Updated: 2022/11/06 12:58:45 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static char	*atoi_skip_spaces(char *nbr)
{
	while (ft_isspace(*nbr))
		nbr++;
	return (nbr);
}

static char	*atoi_parse_sign(char *nbr, int *sign)
{
	*sign = 1;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			*sign = -1;
		return (++nbr);
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		absv;
	char	*nbr;

	absv = 0;
	nbr = (char *)str;
	nbr = atoi_skip_spaces(nbr);
	nbr = atoi_parse_sign(nbr, &sign);
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
			break ;
		absv *= 10;
		absv += *nbr - '0';
		nbr++;
	}
	return (sign * absv);
}
