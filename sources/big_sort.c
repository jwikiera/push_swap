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

static int	int_at_percent_in_arr(const int *arr, int len, int per)
{
	double	one_percent;

	one_percent = (double) len / 100.0;
	return (arr[ft_min_int((int) ((double) per * one_percent), len - 1)]);
}

static int	indexof_target(t_stack *stack, int target)
{
	int	index;

	index = stack->top;
	while (index < stack->size && stack->arr[index] != target)
		index ++;
	if (index == stack->size)
		return (-1);
	return (index);
}

static int	stack_has_smaller_num_than(t_stack *stack, int num)
{
	int	i;

	i = stack->top;
	while (i < stack->size)
	{
		if (stack->arr[i] < num)
			return (1);
		i ++;
	}
	return (0);
}

void	bring_num_to_top(t_stack *stack, int target, t_list **op_lst)
{
	if (indexof_target(stack, target) == -1)
		return ;
	while (stack->arr[stack->top] != target)
	{
		int index = indexof_target(stack, target);
		int index_rel = index - stack->top;
		int half = (stack->size - stack->top) / 2;
		if (index_rel <= half)
			op_r(stack, op_lst);
		else
			op_rr(stack, op_lst);
	}
}

int	get_first_num_smaller_than_target(t_stack *stack, int target)
{
	int	i;

	i = stack->top;
	while (i < stack->size)
	{
		if (stack->arr[i] < target)
			return (stack->arr[i]);
		i ++;
	}
	return (0);
}

void	ps_bigsort(int *arr, int len, t_list **op_lst)
{
	int		*sorted_array;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		cache_counter;

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
	while (stack_a->top != -1)
	{
		sorted_array = intarr_bubblesort(stack_a->arr + stack_a->top, stack_a->size - stack_a->top);
		if (sorted_array == NULL)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return ;
		}
		int	pivot = int_at_percent_in_arr(sorted_array, stack_a->size - stack_a->top, PIVOT);
		int	pivot_b = int_at_percent_in_arr(sorted_array, stack_a->size - stack_a->top, (int)((double) PIVOT / 100.0 * (double) PIVOT));

		while (stack_has_smaller_num_than(stack_a, pivot))
		{
			int	smaller = get_first_num_smaller_than_target(stack_a, pivot);
			bring_num_to_top(stack_a, smaller, op_lst);
			op_p(stack_a, stack_b, op_lst);
			if (stack_b->arr[stack_b->top] < pivot_b)
				op_r(stack_b, op_lst);
		}
		if (stack_a->top == stack_a->size - 1)
			op_p(stack_a, stack_b, op_lst);

		free(sorted_array);
		sorted_array = NULL;
	}

	for (int k = 0; k < stack_a->size; ++k) {
		stack_a->arr[k] = 0;
	}

	int	sort_index = stack_b->size - 1;
	sorted_array = intarr_bubblesort(stack_b->arr, stack_b->size);
	if (sorted_array == NULL)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return ;
	}

	cache_counter = 0;
	while (stack_b->top != -1)
	{
		if (sort_index != stack_b->size - (cache_counter) && sort_index > (cache_counter) && stack_b->arr[stack_b->top] == sorted_array[sort_index - (cache_counter + 1)])
		{
			op_p(stack_b, stack_a, op_lst);
			//op_r(stack_a, op_lst);
			cache_counter ++;
		}
		else
		{
			for (int i = 0; i < cache_counter; ++i) {
				op_r(stack_a, op_lst);
			}
			bring_num_to_top(stack_b, sorted_array[sort_index], op_lst);
			op_p(stack_b, stack_a, op_lst);
			while (cache_counter > 0)
			{
				op_rr(stack_a, op_lst);
				cache_counter --;
				sort_index --;
			}
			sort_index --;
		}
	}
	//free(sorted_array);

	//print_stack(stack_a);
	//print_stack(stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	free(sorted_array);
}
