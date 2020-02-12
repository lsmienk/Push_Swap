/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:42:18 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/02 17:12:09 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		min_first(t_setting *set, t_stack *ar, char x)
{
	if (ar->len == 3)
	{
		rev_rotate(ar, x);
		swap(set, x);
	}
	else
	{
		rotate(ar, x);
		swap(set, x);
		rev_rotate(ar, x);
	}
}

static void		mid_first(t_setting *set, t_stack *ar, char x)
{
	if (ar->len == 3)
	{
		if (ar->stack[ar->len - 3] == ar->min)
			rev_rotate(ar, x);
		else
			swap(set, x);
	}
	else
	{
		if (ar->stack[ar->len - 3] == ar->min)
		{
			rotate(ar, x);
			swap(set, x);
			rev_rotate(ar, x);
		}
		swap(set, x);
	}
}

static void		max_first(t_setting *set, t_stack *ar, char x)
{
	if (ar->len == 3)
	{
		if (ar->stack[ar->len - 2] == ar->min)
			rotate(ar, x);
		else
		{
			swap(set, x);
			rev_rotate(ar, x);
		}
	}
	else
	{
		swap(set, x);
		if (ar->stack[ar->len - 1] == ar->min)
			min_first(set, ar, x);
		else
			mid_first(set, ar, x);
	}
}

void			sort_three(t_setting *set, t_stack *ar, char x)
{
	if (is_sorted(ar, 3))
		return ;
	set_min_max(ar, 3);
	if (ar->stack[ar->len - 1] == ar->max)
		max_first(set, ar, x);
	else if (ar->stack[ar->len - 1] == ar->min)
		min_first(set, ar, x);
	else
		mid_first(set, ar, x);
}
