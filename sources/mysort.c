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

static int	indexof_target(t_stack *stack, int target)
{
	int	index;

	index = stack->top;
	while (stack->arr[index] != target)
		index ++;
	return (index);
}

void	ps_mysort(int *arr, int len)
{
	int		*sorted_array;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		sort_index;

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
	sorted_array = intarr_bubblesort(arr, len);
	if (sorted_array == NULL)
	{
		free(stack_b);
		return ;
	}
	//ft_printf("sorted\n");
	sort_index = 0;
	while (stack_a->top != stack_a->size - 2)
	{
		if (indexof_target(stack_a, sorted_array[sort_index]) == stack_a->top)
		{
			op_p(stack_a, stack_b, 1);
			sort_index ++;
		}
		else
		{
			int index = indexof_target(stack_a, sorted_array[sort_index]);
			int index_rel = index - stack_a->top;
			int half = (stack_a->size - stack_a->top) / 2;
			if (index_rel <= half)
				op_r(stack_a, 1);
			else
				op_rr(stack_a, 1);
		}
	}
	if (stack_a->arr[stack_a->top] > stack_a->arr[stack_a->top + 1])
		op_s(stack_a, 1);
	while (stack_b->top != -1)
		op_p(stack_b, stack_a, 1);
	//print_stack(stack_a);
	//print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(sorted_array);
}
