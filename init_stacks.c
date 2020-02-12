/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 13:35:38 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/03 13:36:07 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_setting *set, int argc)
{
	set->a = (t_stack *)malloc(sizeof(t_stack));
	set->b = (t_stack *)malloc(sizeof(t_stack));
	set->a->stack = (int *)malloc(sizeof(int) * (argc));
	set->b->stack = (int *)ft_memalloc(sizeof(int) * (argc));
	set->b->len = 0;
}
