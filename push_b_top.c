/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_b_top.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 14:12:33 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 15:15:14 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_back(t_setting *set, int pb)
{
	int x;

	x = set->b->len - pb;
	if (pb > x)
	{
		while (x > 0)
		{
			rotate(set->b, 'b');
			x--;
		}
	}
	else
	{
		while (pb > 0)
		{
			rev_rotate(set->b, 'b');
			pb--;
		}
	}
	if (set->b->stack[set->b->len - set->b->len] >
		set->b->stack[set->b->len - 1])
		(rev_rotate(set->b, 'b'));
}

static int		count_push_amount(t_setting *set, int part, int med)
{
	int count;
	int i;

	count = 0;
	i = set->b->len - part;
	while (i < set->b->len)
	{
		if (set->b->stack[i] > med)
			count++;
		i++;
	}
	return (count);
}

int				push_b_top(t_setting *set, int part)
{
	int med;
	int partition;
	int len;
	int pb;

	set_min_max(set->b, part);
	med = get_medium(set->b->min, set->b->max, part);
	len = count_push_amount(set, part, med);
	partition = len;
	pb = 0;
	while (len > 0)
	{
		if (set->b->stack[set->b->len - 1] > med)
		{
			push(set->b, set->a, 'a');
			len--;
		}
		else
		{
			rotate(set->b, 'b');
			pb++;
		}
	}
	push_back(set, pb);
	return (partition);
}
