/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_clean(t_stack *s1, t_stack *s2, int *arr)
{
	if (s1)
		free_stack(s1);
	if (s2)
		free_stack(s2);
	if (arr)
		free(arr);
}

static int	init_stacks(t_stack **stack_a,
				t_stack **stack_b, const int *arr, int len)
{
	*stack_a = stack_init(arr, len, 'a');
	if (!*stack_a)
		return (0);
	*stack_b = stack_init_empty(len, 'b');
	if (!*stack_b)
	{
		free(stack_a);
		return (0);
	}
	return (1);
}

void	ps_bigsort(const int *arr, int len, t_list **op_lst, int *params)
{
	int		*sorted_array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!init_stacks(&stack_a, &stack_b, arr, len))
		return ;
	if (b_loop_one(stack_a, stack_b, params, op_lst) == -1)
	{
		b_clean(stack_a, stack_b, 0);
		return ;
	}
	sorted_array = ft_intarr_bubblesort(stack_b->arr + stack_b->top,
			stack_len(stack_b));
	if (sorted_array == NULL)
	{
		b_clean(stack_a, stack_b, 0);
		return ;
	}
	b_loop_two(stack_a, stack_b, sorted_array, op_lst);
	b_clean(stack_a, stack_b, sorted_array);
}
