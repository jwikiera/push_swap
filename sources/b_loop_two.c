/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_loop_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_loop_two(t_stack *stack_a, t_stack *stack_b, int *sorted_array, t_list **op_lst)
{
	int cache_size;

	cache_size = 0;
	int index = stack_len(stack_b) - 1;
	while (stack_b->top != -1)
	{
		if (index > cache_size && top_val(stack_b) == sorted_array[index - 1 - cache_size])
		{
			cache_size ++;
			op_p(stack_b, stack_a, op_lst);
		}
		else
		{
			bring_num_to_top(stack_b, sorted_array[index], op_lst);
			int	i = 0;
			while (i < cache_size)
			{
				op_r(stack_a, op_lst);
				i ++;
			}
			op_p(stack_b, stack_a, op_lst);
			index -= (cache_size + 1);
			while (cache_size > 0)
			{
				op_rr(stack_a, op_lst);
				cache_size --;
			}
		}
	}
}
