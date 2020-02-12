/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:34:33 by lorenasmien    #+#    #+#                */
/*   Updated: 2019/12/28 13:11:32 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack *take, t_stack *put, char x)
{
	put->stack[put->len] = take->stack[take->len - 1];
	take->stack[take->len - 1] = 0;
	put->len++;
	take->len--;
	if (x == 'a')
		ft_printf("pa\n");
	if (x == 'b')
		ft_printf("pb\n");
}
