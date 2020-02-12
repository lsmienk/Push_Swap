/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lorenasmienk <lorenasmienk@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/27 09:20:42 by lorenasmien    #+#    #+#                */
/*   Updated: 2020/01/03 13:36:17 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_stack
{
	int			*stack;
	int			len;
	int			min;
	int			max;
}				t_stack;

typedef struct	s_setting
{
	int			min;
	int			max;
	int			total;
	t_stack		*a;
	t_stack		*b;
}				t_setting;

int				is_sorted(t_stack *ar, int len);
void			create_stack(int argc, char **argv, t_setting *set);
void			print_stack(t_stack *stack);
void			push(t_stack *take, t_stack *put, char x);
void			rotate(t_stack *ar, char x);
void			rev_rotate(t_stack *ar, char x);
void			swap(t_setting *set, char x);
void			small_sort(t_setting *set, int part);
void			sort_three(t_setting *set, t_stack *ar, char x);
int				get_medium(int min, int max, int range);
void			set_min_max(t_stack *ar, int range);
void			partition_sort_a(t_setting *set, int part);
void			partition_sort_b(t_setting *set, int part);
int				push_top(t_setting *set, int part);
int				push_b_top(t_setting *set, int part);
void			initial_devide(t_setting *set);
void			sort_three_rev(t_setting *set, t_stack *ar, int len, char x);
int				is_rev_sorted(t_stack *ar, int len);
void			free_set(t_setting *set);
void			small_b_stack(t_setting *set, int part);
void			short_stack_sort(t_setting *set);
void			check_swap(t_setting *set, char x);
int				ret_sorted_bstack(t_setting *set, int part);
void			init_stacks(t_setting *set, int argc);

#endif
