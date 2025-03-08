/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:08:22 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/20 16:08:45 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

unsigned int	parse_uint(const char *str)
{
	long	tmp;

	if (str == NULL || *str == '\0' || !ft_strall(str, ft_isdigit))
		exit_with_error(EXIT_PARSE_ERROR, "parse_uint: invalid format");
	errno = 0;
	tmp = ft_atol(str);
	if (errno != 0 || tmp > UINT_MAX)
		exit_with_error(EXIT_PARSE_ERROR, "parse_uint: too large number");
	return ((unsigned int)tmp);
}
