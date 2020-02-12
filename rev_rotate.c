/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:37:16 by lorenasmien    #+#    #+#                */
/*   Updated: 2019/12/27 14:43:10 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rev_rotate(t_stack *ar, char x)
{
	int	temp;
	int	i;

	temp = ar->stack[0];
	i = 0;
	while (i < (ar->len - 1))
	{
		ar->stack[i] = ar->stack[i + 1];
		i++;
	}
	ar->stack[i] = temp;
	if (x == 'a')
		ft_printf("rra\n");
	if (x == 'b')
		ft_printf("rrb\n");
}
