/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluc_screen_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:40:02 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:44:28 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	caluc_screen_point(int x, int y)
{
	t_vec3	screen;

	screen.x = x - WIDTH / 2;
	screen.y = HEIGHT / 2 - y;
	screen.z = 0;
	return (screen);
}
