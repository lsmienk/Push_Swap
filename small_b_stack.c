/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_b_stack.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:40:31 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/02 14:04:56 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ret_bstack(t_setting *set, int len)
{
	while (len > 0)
	{
		push(set->b, set->a, 'a');
		len--;
	}
}

void			small_b_stack(t_setting *set, int part)
{
	if (part == 3 || part == 2 || part == 1)
	{
		if (part == 3)
		{
			sort_three_rev(set, set->b, part, 'b');
		}
		if (part == 2 && (is_sorted(set->b, 2)))
			swap(set, 'b');
	}
	ret_bstack(set, part);
}
