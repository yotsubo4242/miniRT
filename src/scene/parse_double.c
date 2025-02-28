/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:01:03 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/19 16:29:16 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

static	const char	*atof_integer_part(const char *str, double *result)
{
	int	digit;

	*result = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (*result > (HUGE_VAL - digit) / 10)
		{
			errno = ERANGE;
			return (NULL);
		}
		*result = *result * 10 + digit;
		++str;
	}
	return (str);
}

// ignore under flow
static const char	*atof_decimal_part(const char *str, double *result)
{
	int		digit;
	double	scale;

	*result = 0;
	scale = 0.1;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		*result += digit * scale;
		scale *= 0.1;
		++str;
	}
	return (str);
}

// atof return's HUGE_VAL insted of DBL_MAX
static double	ft_atof(const char *str)
{
	double	integer;
	double	decimal;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	errno = 0;
	str = atof_integer_part(str, &integer);
	if (errno == ERANGE)
	{
		if (sign < 0)
			return (-HUGE_VAL);
		return (HUGE_VAL);
	}
	decimal = 0;
	if (*str == '.')
	{
		++str;
		atof_decimal_part(str, &decimal);
	}
	return (sign * (integer + decimal));
}

// according to bc
// valid: 1, 1.0, 1., .1, -1, -1.0, -1., -.1
// invalid: +1.2, 1.2.3, 1e-2
bool	is_valid_double(const char *str)
{
	bool	dot_found;

	dot_found = false;
	if (str == NULL || *str == 0)
		return (false);
	if (!(*str == '-' || *str == '.' || ft_isdigit(*str)))
		return (false);
	if (*str == '-')
		++str;
	while (*str)
	{
		if (*str == '.')
		{
			if (dot_found)
				return (false);
			dot_found = true;
		}
		else if (!ft_isdigit(*str))
			return (false);
		++str;
	}
	return (true);
}

double	parse_double(const char *str)
{
	double	result;

	errno = 0;
	result = 0;
	if (!is_valid_double(str))
		exit_with_error(EXIT_PARSE_ERROR, "parse_double: invalid format");
	result = ft_atof(str);
	if (errno != 0)
		exit_with_error(EXIT_PARSE_ERROR, "parse_double: invalid value");
	return (result);
}
