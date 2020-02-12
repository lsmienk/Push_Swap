/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three_rev.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 20:20:52 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/02 15:05:30 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		max_first(t_setting *set, t_stack *ar, char x)
{
	rotate(ar, x);
	swap(set, x);
	rev_rotate(ar, x);
}

static void		mid_first(t_setting *set, t_stack *ar, char x)
{
	if (ar->len == 3 && ar->stack[ar->len - 2] == ar->min)
		rev_rotate(ar, x);
	else
	{
		if (ar->stack[ar->len - 2] == ar->min)
		{
			rotate(ar, x);
			swap(set, x);
			rev_rotate(ar, x);
		}
		swap(set, x);
	}
}

static void		min_first(t_setting *set, t_stack *ar, char x)
{
	swap(set, x);
	if (ar->stack[ar->len - 1] == ar->max)
		max_first(set, ar, x);
	else
		mid_first(set, ar, x);
}

void			sort_three_rev(t_setting *set, t_stack *ar, int len, char x)
{
	if (is_rev_sorted(ar, len))
		return ;
	set_min_max(ar, len);
	if (ar->stack[ar->len - 1] == ar->max)
		max_first(set, ar, x);
	else if (ar->stack[ar->len - 1] == ar->min)
		min_first(set, ar, x);
	else
		mid_first(set, ar, x);
}
