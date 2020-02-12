/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   partition_sort_b.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 13:51:55 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 13:35:12 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ret_rev_sorted_stack(t_setting *set, int part)
{
	set_min_max(set->b, part);
	while (part > 0 && set->b->stack[set->b->len - 1] == set->b->max)
	{
		push(set->b, set->a, 'a');
		part--;
	}
	return (part);
}

void			partition_sort_b(t_setting *set, int part)
{
	int p_part;

	p_part = 0;
	set_min_max(set->b, part);
	part = ret_rev_sorted_stack(set, part);
	while (part > 3)
	{
		part = ret_rev_sorted_stack(set, part);
		if (is_sorted(set->b, part))
			part = ret_sorted_bstack(set, part);
		p_part = push_b_top(set, part);
		if (p_part <= 3)
			small_sort(set, p_part);
		else
			partition_sort_a(set, p_part);
		part -= p_part;
	}
	small_b_stack(set, part);
}
