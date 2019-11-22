/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:32:43 by lmartin           #+#    #+#             */
/*   Updated: 2019/11/22 05:51:24 by lmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

s_triangle	*new_triangle(s_vector* a, s_vector *b, s_vector *c, int color)
{
	s_triangle *triangle;

	if (!(triangle = malloc(sizeof(s_triangle))))
		return (NULL);
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	triangle->u = subtract_vectors(*triangle->b, *triangle->a);
	triangle->v = subtract_vectors(*triangle->c, *triangle->a);
	triangle->normal = cross(*triangle->u, *triangle->v);
	triangle->dot_uu = product_vectors(*triangle->u, *triangle->u);
	triangle->dot_uv = product_vectors(*triangle->u, *triangle->v);
	triangle->dot_vv = product_vectors(*triangle->v, *triangle->v);
	triangle->color = color;
	triangle->shiny = -1;
	triangle->reflective = -1;
	triangle->calcul_a = 0;
	triangle->calcul_d = triangle->dot_uv * triangle->dot_uv - triangle->dot_uu * triangle->dot_vv;
	triangle->prev_origin = NULL;
	return (triangle);
}

void		free_triangle(s_triangle *triangle)
{
	free(triangle->a);
	free(triangle->b);
	free(triangle->c);
	free(triangle->u);
	free(triangle->v);
	free(triangle->normal);
	if (triangle->prev_origin)
		free(triangle->prev_origin);
	free(triangle);
}

s_triangle	*cpy_triangle(s_triangle *triangle)
{
	s_triangle *new;

	if (!(new = malloc(sizeof(s_triangle))))
		return (NULL);
	new->a = cpy_vector(triangle->a);
	new->b = cpy_vector(triangle->b);
	new->c = cpy_vector(triangle->c);
	new->u = cpy_vector(triangle->u);
	new->v = cpy_vector(triangle->v);
	new->normal = cpy_vector(triangle->normal);
	new->dot_uu = triangle->dot_uu;
	new->dot_uv = triangle->dot_uv;
	new->dot_vv = triangle->dot_vv;
	new->color = triangle->color;
	new->shiny = triangle->shiny;
	new->reflective = triangle->reflective;
	new->calcul_a = 0;
	new->calcul_d = triangle->calcul_d;
	new->prev_origin = NULL;
	return (new);
}
