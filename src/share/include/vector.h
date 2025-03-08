/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:32:10 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/23 15:16:26 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <math.h>
# include "libft.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

t_vec3		vec_normalize(t_vec3 a);
bool		vec_is_normalized(t_vec3 v);
double		vec_mag(t_vec3 a);
double		vec_dot(t_vec3 a, t_vec3 b);
bool		vec_eq(t_vec3 a, t_vec3 b);
t_vec3		vec_minus(t_vec3 a, t_vec3 b);
t_vec3		vec_mult(double x, t_vec3 v);
t_vec3		vec_rev(t_vec3 v);
t_vec3		vec_plus(t_vec3 a, t_vec3 b);
t_vec3		vec_cross(t_vec3 a, t_vec3 b);
t_vec3		vec_div(t_vec3 a, double b);
t_vec3		*vec_dup(t_vec3 a);

#endif 
