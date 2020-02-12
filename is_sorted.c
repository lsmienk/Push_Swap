/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:31:03 by lorenasmien    #+#    #+#                */
/*   Updated: 2019/12/30 15:15:02 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_sorted(t_stack *ar, int len)
{
	int i;
	int big;

	i = ar->len - len;
	big = ar->stack[i];
	while (i < ar->len)
	{
		if (ar->stack[i] > big)
			return (0);
		big = ar->stack[i];
		i++;
	}
	return (1);
}
