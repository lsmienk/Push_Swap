/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   partition_sort_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:43:32 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 12:06:37 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_sorted(t_setting *set, int part)
{
	set_min_max(set->a, part);
	while (part > 0 && set->a->stack[set->a->len - set->a->len] == set->a->min)
	{
		part--;
	}
	return (part);
}

static void	push_part(t_setting *set, int part)
{
	while (part > 0)
	{
		push(set->a, set->b, 'b');
		part--;
	}
}

void		partition_sort_a(t_setting *set, int part)
{
	int p_part;
	int x;

	p_part = 0;
	x = 0;
	while (part > 3)
	{
		if (is_rev_sorted(set->a, part))
		{
			push_part(set, part);
			part = ret_sorted_bstack(set, part);
			break ;
		}
		part = count_sorted(set, part);
		x = push_top(set, part);
		part -= x;
		p_part += x;
	}
	small_sort(set, part);
	if (p_part > 3)
		partition_sort_b(set, p_part);
	else
		small_b_stack(set, p_part);
}
