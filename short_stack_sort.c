/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_stack_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/28 12:24:19 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/03 14:00:15 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_short_stack(t_setting *set)
{
	int len;

	len = set->a->len - 1;
	while (set->a->len > 3)
	{
		set_min_max(set->a, set->a->len);
		if (set->a->stack[set->a->len - 1] == set->a-> min)
		{
			push(set->a, set->b, 'b');
		}
		else
			rotate(set->a, 'a');
	}
	small_sort(set, set->a->len);
	small_b_stack(set, set->b->len);
}

void		short_stack_sort(t_setting *set)
{
	if (is_sorted(set->a, set->a->len))
		return ;
	if (set->a->len <= 3)
		small_sort(set, set->a->len);
	else
		split_short_stack(set);
}
