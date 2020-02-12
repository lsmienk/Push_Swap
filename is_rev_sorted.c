/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_rev_sorted.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 20:24:35 by lorenasmien    #+#    #+#                */
/*   Updated: 2019/12/28 12:14:21 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_rev_sorted(t_stack *ar, int len)
{
	int i;

	i = ar->len - 1;
	while (len > 1 && i > 0)
	{
		if (ar->stack[i] < ar->stack[i - 1])
			return (0);
		i--;
		len--;
	}
	return (1);
}
