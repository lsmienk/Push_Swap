/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:38:01 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 14:50:39 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		double_swap(t_setting *set, int temp)
{
	temp = set->b->stack[set->b->len - 1];
	set->b->stack[set->b->len - 1] = set->b->stack[set->b->len - 2];
	set->b->stack[set->b->len - 2] = temp;
	temp = set->a->stack[set->a->len - 1];
	set->a->stack[set->a->len - 1] = set->a->stack[set->a->len - 2];
	set->a->stack[set->a->len - 2] = temp;
	ft_printf("ss\n");
}

void			swap(t_setting *set, char x)
{
	int		temp;

	temp = 0;
	if (x == 'a')
	{
		if (set->b->stack[set->b->len - 1] < set->b->stack[set->b->len - 2] &&
			set->b->stack[set->b->len - 2] != 0 && set->b->len > 1)
			double_swap(set, temp);
		else
		{
			temp = set->a->stack[set->a->len - 1];
			set->a->stack[set->a->len - 1] = set->a->stack[set->a->len - 2];
			set->a->stack[set->a->len - 2] = temp;
			ft_printf("sa\n");
		}
	}
	if (x == 'b')
	{
		temp = set->b->stack[set->b->len - 1];
		set->b->stack[set->b->len - 1] = set->b->stack[set->b->len - 2];
		set->b->stack[set->b->len - 2] = temp;
		ft_printf("sb\n");
	}
}
