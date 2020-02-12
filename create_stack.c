/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 11:15:48 by lsmienk        #+#    #+#                */
/*   Updated: 2019/12/30 16:11:21 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_valid(t_setting *set, char *ar, int count)
{
	if (!ft_isdigit(ar[0]) && ar[0] != '-')
		return (0);
	if (ft_atoi(ar) < INT_MIN || ft_atoi(ar) > INT_MAX)
		return (0);
	while (count >= 0)
	{
		if (ft_atoi(ar) == set->a->stack[count] && ft_atoi(ar) != 0)
			return (0);
		count--;
	}
	return (1);
}

void		create_stack(int argc, char **argv, t_setting *set)
{
	int i;
	int top;

	i = 0;
	top = argc - 1;
	while (i < argc)
	{
		if ((check_valid(set, argv[top - i], i)))
			set->a->stack[i] = ft_atoi(argv[top - i]);
		else
		{
			free_set(set);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
		set->a->len = i;
		set_min_max(set->a, set->a->len);
		set->min = set->a->min;
		set->max = set->a->max;
		set->total = i;
	}
}
