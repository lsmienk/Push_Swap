/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_set.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 11:03:11 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/27 11:04:09 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_set(t_setting *set)
{
	free(set->a->stack);
	free(set->b->stack);
	free(set->a);
	free(set->b);
	free(set);
	set = NULL;
}
