/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:54:17 by dfreire        #+#    #+#                */
/*   Updated: 2020/01/03 15:38:18 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		**split_args(int *argc, char ***argv)
{
	char **tmp;

	tmp = ft_strsplit((*argv)[0], ' ');
	*argc = 0;
	while (tmp && tmp[*argc])
		(*argc)++;
	if (argc == 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (tmp);
}

int				main(int argc, char **argv)
{
	t_setting *set;

	if (argc != 2)
	{
		ft_putstr("usage: ./push_swap ['integer stack']\n");
		exit(0);
	}
	argv++;
	argc--;
	set = (t_setting *)malloc(sizeof(t_setting));
	if (argc == 1)
		argv = split_args(&argc, &argv);
	init_stacks(set, argc);
	create_stack(argc, argv, set);
	if (set->a->len <= 6)
		short_stack_sort(set);
	else
		initial_devide(set);
	free_set(set);
	return (0);
}
