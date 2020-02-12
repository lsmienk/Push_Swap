/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_top.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 13:36:05 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 13:30:41 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_back(t_setting *set, int pb)
{
	int x;

	x = set->a->len - pb;
	if (pb > x)
	{
		while (x > 0)
		{
			rotate(set->a, 'a');
			x--;
		}
	}
	else
	{
		while (pb > 0)
		{
			rev_rotate(set->a, 'a');
			pb--;
		}
	}
}

static int		count_push_amount(t_setting *set, int part, int med)
{
	int count;
	int i;

	count = 0;
	i = set->a->len - part;
	while (i < set->a->len)
	{
		if (set->a->stack[i] < med)
			count++;
		i++;
	}
	return (count);
}

int				push_top(t_setting *set, int part)
{
	int med;
	int partition;
	int len;
	int pb;

	set_min_max(set->a, part);
	med = get_medium(set->a->min, set->a->max, part);
	len = count_push_amount(set, part, med);
	pb = 0;
	partition = len;
	while (len > 0)
	{
		if (set->a->stack[set->a->len - 1] < med)
		{
			push(set->a, set->b, 'b');
			len--;
		}
		else
		{
			rotate(set->a, 'a');
			pb++;
		}
	}
	push_back(set, pb);
	return (partition);
}
