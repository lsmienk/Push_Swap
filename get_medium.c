/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_medium.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/26 13:36:47 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 15:07:09 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_medium(int min, int max, int range)
{
	int med;

	med = ((min + max) / 2);
	if (range == 4)
		med = min + 1;
	if (med > max || med < min)
		med = ((min + max) / 2);
	return (med);
}
