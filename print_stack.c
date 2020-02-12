/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:32:09 by lorenasmien    #+#    #+#                */
/*   Updated: 2019/12/27 14:44:42 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				print_stack(t_stack *stack)
{
	int i;

	i = stack->len - 1;
	while (i >= 0)
	{
		ft_printf("%i\n", stack->stack[i]);
		i--;
	}
}
