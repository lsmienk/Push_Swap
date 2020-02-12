/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_devide.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 19:46:14 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 14:46:29 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_part(t_setting *set, int part)
{
	while (part > 0)
	{
		push(set->a, set->b, 'b');
		part--;
	}
}

static int	count_push_amount(t_setting *set, int part, int med)
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

static int	initial_push(t_setting *set, int partition)
{
	int med;
	int len;

	med = ((set->a->min + set->a->max) / 2);
	if (set->a->len > 400)
		med = ((set->a->min + set->a->max) / 3.5);
	len = count_push_amount(set, set->a->len, med);
	while (len > 0)
	{
		if (set->a->stack[set->a->len - 1] < med)
		{
			push(set->a, set->b, 'b');
			partition++;
			len--;
		}
		else
		{
			rotate(set->a, 'a');
		}
	}
	return (partition);
}

static void	partition_sort(t_setting *set, int *partition, int i)
{
	while (i >= 0)
	{
		if (is_sorted(set->b, partition[i]) && partition[i] > 0)
		{
			partition[i] = ret_sorted_bstack(set, partition[i]);
			i--;
		}
		if (partition[i] == 1)
			push(set->b, set->a, 'a');
		if (partition[i] > 1)
			partition_sort_b(set, partition[i]);
		i--;
	}
}

void		initial_devide(t_setting *set)
{
	int *partition;
	int i;

	partition = ft_memalloc(set->total * sizeof(int));
	i = 0;
	while (set->a->len > 3)
	{
		if (is_sorted(set->a, set->a->len))
			break ;
		if (is_rev_sorted(set->a, set->a->len))
		{
			partition[i] = set->a->len;
			push_part(set, set->a->len);
			partition[i] = ret_sorted_bstack(set, partition[i]);
			break ;
		}
		set_min_max(set->a, set->a->len);
		partition[i] = initial_push(set, 0);
		i++;
	}
	small_sort(set, set->a->len);
	partition_sort(set, partition, i);
	free(partition);
}
