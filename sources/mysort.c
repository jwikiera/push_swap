/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	msindexof_target(t_stack *stack, int target)
{
	int	index;

	index = stack->top;
	while (stack->arr[index] != target)
		index ++;
	return (index);
}

static void	ps_mysort_two(t_stack *stack_a, t_stack *stack_b,
				int *sorted_array, t_list **op_lst)
{
	int		sort_index;

	sort_index = 0;
	while (stack_a->top != stack_a->size - 2)
	{
		if (msindexof_target(stack_a, sorted_array[sort_index]) == stack_a->top)
		{
			op_p(stack_a, stack_b, op_lst);
			sort_index ++;
		}
		else
		{
			if (msindexof_target(stack_a,
					sorted_array[sort_index]) - stack_a->top
				<= (stack_a->size - stack_a->top) / 2)
				op_r(stack_a, op_lst);
			else
				op_rr(stack_a, op_lst);
		}
	}
	if (stack_a->arr[stack_a->top] > stack_a->arr[stack_a->top + 1])
		op_s(stack_a, op_lst);
	while (stack_b->top != -1)
		op_p(stack_b, stack_a, op_lst);
}

static void	free_stacks(t_stack *s1, t_stack *s2)
{
	free_stack(s1);
	free_stack(s2);
}

void	ps_mysort(int *arr, int len, t_list **op_lst)
{
	int		*sorted_array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init(arr, len, 'a');
	if (!stack_a)
	{
		free(arr);
		return ;
	}
	stack_b = stack_init_empty(len, 'b');
	if (!stack_b)
	{
		free(stack_a);
		return ;
	}
	sorted_array = ft_intarr_bubblesort(arr, len);
	if (sorted_array == NULL)
	{
		free(stack_b);
		return ;
	}
	ps_mysort_two(stack_a, stack_b, sorted_array, op_lst);
	free_stacks(stack_a, stack_b);
	free(sorted_array);
}
