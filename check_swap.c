/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_swap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:06:07 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/30 15:27:15 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check_swap(t_setting *set, char x)
{
	int		temp;

	if (x == 'a')
	{
		temp = set->a->stack[set->a->len - 1];
		set->a->stack[set->a->len - 1] = set->a->stack[set->a->len - 2];
		set->a->stack[set->a->len - 2] = temp;
	}
	if (x == 'b')
	{
		temp = set->b->stack[set->b->len - 1];
		set->b->stack[set->b->len - 1] = set->b->stack[set->b->len - 2];
		set->b->stack[set->b->len - 2] = temp;
	}
}
