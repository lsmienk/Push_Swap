/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ret_sorted_bstack.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 16:21:15 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/02 16:57:05 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ret_sorted_bstack(t_setting *set, int part)
{
	int x;

	x = part;
	while (x > 1)
	{
		rotate(set->b, 'b');
		x--;
	}
	while (x < part)
	{
		push(set->b, set->a, 'a');
		rev_rotate(set->b, 'b');
		x++;
	}
	push(set->b, set->a, 'a');
	return (0);
}
