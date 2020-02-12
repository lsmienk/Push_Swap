/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_min_max.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:55:58 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 15:15:04 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_min_max(t_stack *ar, int range)
{
	int i;

	i = ar->len - range;
	ar->max = -2147483648;
	ar->min = 2147483647;
	while (i < ar->len)
	{
		if (ar->stack[i] > ar->max)
			ar->max = ar->stack[i];
		if (ar->stack[i] < ar->min)
			ar->min = ar->stack[i];
		i++;
	}
}
