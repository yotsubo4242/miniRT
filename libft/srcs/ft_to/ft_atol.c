/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:10:20 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/20 16:10:25 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <errno.h>

static int	skip_to_number(const char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
	if (**s && **s == '-')
	{
		(*s)++;
		return (-1);
	}
	if (**s && **s == '+')
		(*s)++;
	return (1);
}

static int	is_overflow(int sign, unsigned long num, unsigned long x)
{
	unsigned long	limit;

	if (sign > 0)
		limit = LONG_MAX;
	else
		limit = (unsigned long)LONG_MAX + 1;
	return (limit / 10 < num || limit - num * 10 < x);
}

long	ft_atol(const char *str)
{
	int				sign;
	unsigned long	num;
	unsigned long	x;

	num = 0;
	sign = skip_to_number(&str);
	if (!ft_isdigit(*str))
		errno = EINVAL;
	while (ft_isdigit(*str))
	{
		x = *str++ - '0';
		if (is_overflow(sign, num, x))
		{
			errno = ERANGE;
			if (sign > 0)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		num = num * 10 + x;
	}
	while (*str && ft_isspace(*str))
		str++;
	if (*str)
		errno = EINVAL;
	return ((long)(num * sign));
}
