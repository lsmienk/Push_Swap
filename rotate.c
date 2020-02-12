/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:35:57 by lorenasmien    #+#    #+#                */
/*   Updated: 2019/12/27 14:43:10 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rotate(t_stack *ar, char x)
{
	int	temp;
	int	i;

	temp = ar->stack[ar->len - 1];
	i = ar->len;
	while (i > 0)
	{
		ar->stack[i - 1] = ar->stack[i - 2];
		i--;
	}
	ar->stack[i] = temp;
	if (x == 'a')
		ft_printf("ra\n");
	if (x == 'b')
		ft_printf("rb\n");
}
