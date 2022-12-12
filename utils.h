/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalker <twalker@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:59:09 by twalker           #+#    #+#             */
/*   Updated: 2022/12/02 12:53:59 by twalker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);
void	*ft_memchr(const void *s, int c, size_t n);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
char	*ft_u2a(
			unsigned long long value,
			char *ret,
			char *digits,
			unsigned int radix);

#endif
