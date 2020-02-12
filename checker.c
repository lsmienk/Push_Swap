/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 11:06:02 by lsmienk        #+#    #+#                */
/*   Updated: 2020/01/03 15:38:18 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_more(t_setting *set, char *op)
{
	if (ft_strequ(op, "ra"))
		rotate(set->a, 'x');
	else if (ft_strequ(op, "rb"))
		rotate(set->b, 'x');
	else if ((ft_strequ(op, "rr")))
	{
		rotate(set->a, 'x');
		rotate(set->b, 'x');
	}
	else if (ft_strequ(op, "rra"))
		rev_rotate(set->a, 'x');
	else if ((ft_strequ(op, "rrr")))
	{
		rev_rotate(set->a, 'x');
		rev_rotate(set->b, 'x');
	}
	else if (ft_strequ(op, "rrb"))
		rev_rotate(set->b, 'x');
}

static int	do_opperations(t_setting *set, char *op)
{
	if (ft_strequ(op, "sa"))
		check_swap(set, 'a');
	else if (ft_strequ(op, "sb"))
		check_swap(set, 'b');
	else if (ft_strequ(op, "ss"))
	{
		check_swap(set, 'a');
		check_swap(set, 'b');
	}
	else if (ft_strequ(op, "pa"))
		push(set->b, set->a, 'x');
	else if (ft_strequ(op, "pb"))
		push(set->a, set->b, 'x');
	else if (ft_strequ(op, "ra") || ft_strequ(op, "rb") || ft_strequ(op, "rr")
		|| ft_strequ(op, "rra") || ft_strequ(op, "rrr") || ft_strequ(op, "rrb"))
	{
		do_more(set, op);
		return (0);
	}
	else
		return (-1);
	return (0);
}

static void	read_opperations(t_setting *set)
{
	char *op;

	while (ft_get_next_line(0, &op) > 0)
	{
		if (!op || ft_strcmp(op, "\n") == 0)
			break ;
		if (do_opperations(set, op))
		{
			ft_putstr("Error\n");
			free_set(set);
			free(op);
			exit(1);
		}
		free(op);
		op = NULL;
	}
	free(op);
}

static char	**split_args(int *argc, char ***argv)
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

int			main(int argc, char **argv)
{
	t_setting *set;

	if (argc == 1)
		exit(0);
	if (argc > 2)
	{
		ft_putstr("usage: ./checker ['integer stack']\n");
		exit(0);
	}
	argv++;
	argc--;
	set = (t_setting *)malloc(sizeof(t_setting));
	if (argc == 1)
		argv = split_args(&argc, &argv);
	init_stacks(set, argc);
	create_stack(argc, argv, set);
	if (!(is_sorted(set->a, set->total)))
		read_opperations(set);
	if (is_sorted(set->a, set->total))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_set(set);
	return (0);
}
