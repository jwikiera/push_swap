/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_loop_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_loop_data_one
{
	int	*sorted_array;
	int	minchunk;
	int	pivot_a;
	int	pivot_b;
}	t_loop_data_one;

static void	helper1(t_loop_data_one *ld, int *params,
				t_stack *stack_a)
{
	ld->pivot_a = int_at_percent_in_arr(ld->sorted_array, stack_len(stack_a),
			params[0]);
	ld->pivot_b = int_at_percent_in_arr(ld->sorted_array, stack_len(stack_a),
			(int)((double) params[1] / 100.0 * (double) params[2]));
	if (ft_index_of_int(ld->sorted_array, stack_len(stack_a),
			ld->pivot_a) == 0 && (stack_len(stack_a) > 1))
		ld->pivot_a = ld->sorted_array[1];
	if (ft_index_of_int(ld->sorted_array, stack_len(stack_a),
			ld->pivot_b) == 0 && (stack_len(stack_a) > 1))
		ld->pivot_b = ld->sorted_array[1];
	if (count_nums_below(stack_a, ld->pivot_a) < ld->minchunk)
		ld->pivot_a = get_num_with_x_below(stack_a, ld->minchunk);
}

static void	helper2(t_loop_data_one *ld, t_stack *stack_a,
				t_stack *stack_b, t_list **op_lst)
{
	while (stack_has_smaller_num_than(stack_a, ld->pivot_a))
	{
		if (top_val(stack_a) < ld->pivot_a)
		{
			op_p(stack_a, stack_b, op_lst);
			while (stack_has_smaller_num_than(stack_a, ld->pivot_a)
				&& top_val(stack_a) > ld->pivot_a)
				op_r(stack_a, op_lst);
			if (top_val(stack_b) < ld->pivot_b)
				op_r(stack_b, op_lst);
		}
		else
			op_r(stack_a, op_lst);
	}
	free(ld->sorted_array);
}

int	b_loop_one(t_stack *stack_a, t_stack *stack_b, int *params, t_list **op_lst)
{
	t_loop_data_one	ld;

	ld.minchunk = params[3];
	while (stack_len(stack_a) != 1)
	{
		if (ld.minchunk > stack_len(stack_a) - 1)
			ld.minchunk = stack_len(stack_a) - 1;
		ld.sorted_array = intarr_bubblesort(stack_a->arr + stack_a->top,
				stack_len(stack_a));
		if (ld.sorted_array == NULL)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (-1);
		}
		helper1(&ld, params, stack_a);
		helper2(&ld, stack_a, stack_b, op_lst);
	}
	return (1);
}
