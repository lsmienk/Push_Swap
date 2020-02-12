/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 12:40:45 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/02 13:55:13 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		small_sort(t_setting *set, int part)
{
	if (part == 3)
		sort_three(set, set->a, 'a');
	if (part == 2)
	{
		if (!is_sorted(set->a, (part)))
			swap(set, 'a');
	}
}
