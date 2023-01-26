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

int	b_loop_one(t_stack *stack_a, t_stack *stack_b, int *params, t_list **op_lst)
{
	int	*sorted_array;
	int	minchunk;

	minchunk = params[3];
	while (stack_len(stack_a) != 1)
	{
		if (minchunk > stack_len(stack_a) - 1)
			minchunk = stack_len(stack_a) - 1;
		sorted_array = intarr_bubblesort(stack_a->arr + stack_a->top, stack_len(stack_a));
		if (sorted_array == NULL)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (-1);
		}
		int	pivot_a = int_at_percent_in_arr(sorted_array, stack_len(stack_a), params[0]);
		int	pivot_b = int_at_percent_in_arr(sorted_array, stack_len(stack_a), (int)((double) params[1] / 100.0 * (double) params[2]));
		if (ft_index_of_int(sorted_array, stack_len(stack_a), pivot_a) == 0 && (stack_len(stack_a) > 1))
			pivot_a = sorted_array[1];
		if (ft_index_of_int(sorted_array, stack_len(stack_a), pivot_b) == 0  && (stack_len(stack_a) > 1))
			pivot_b = sorted_array[1];
		if (count_nums_below(stack_a, pivot_a) < minchunk)
			pivot_a = get_num_with_x_below(stack_a, minchunk);
		while (stack_has_smaller_num_than(stack_a, pivot_a))
		{
			if (top_val(stack_a) < pivot_a)
			{
				op_p(stack_a, stack_b, op_lst);
				while (stack_has_smaller_num_than(stack_a, pivot_a) && top_val(stack_a) > pivot_a)
					op_r(stack_a, op_lst);
				if (top_val(stack_b) < pivot_b)
					op_r(stack_b, op_lst);
			}
			else
				op_r(stack_a, op_lst);
		}
		free(sorted_array);
		sorted_array = NULL;
	}
	return (1);
}
