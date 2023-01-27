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

typedef struct s_loop_data_two
{
	int		cache_size;
	int		index;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_loop_data_two;

static void	helper(t_loop_data_two *ld, int *sorted_array, t_list **op_lst)
{
	int	i;

	bring_num_to_top(ld->stack_b, sorted_array[ld->index], op_lst);
	i = 0;
	while (i < ld->cache_size)
	{
		op_r(ld->stack_a, op_lst);
		i ++;
	}
	op_p(ld->stack_b, ld->stack_a, op_lst);
	ld->index -= (ld->cache_size + 1);
	while (ld->cache_size > 0)
	{
		op_rr(ld->stack_a, op_lst);
		ld->cache_size --;
	}
}

void	b_loop_two(t_stack *stack_a, t_stack *stack_b,
			int *sorted_array, t_list **op_lst)
{
	t_loop_data_two	ld;

	ld.stack_a = stack_a;
	ld.stack_b = stack_b;
	ld.cache_size = 0;
	ld.index = stack_len(stack_b) - 1;
	while (stack_b->top != -1)
	{
		if (ld.index > ld.cache_size && top_val(stack_b)
			== sorted_array[ld.index - 1 - ld.cache_size])
		{
			ld.cache_size ++;
			op_p(stack_b, stack_a, op_lst);
		}
		else
			helper(&ld, sorted_array, op_lst);
	}
}
