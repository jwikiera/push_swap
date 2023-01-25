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
	return (arr[ft_max_int(0, ft_min_int((int) ((double) per * one_percent), len - 1))]);
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

int	get_largest_num_in_stack(t_stack *stack)
{
	int	i;
	int	res;

	if (stack->top == -1)
		return (0);
	res = stack->arr[stack->top];
	i = stack->top + 1;
	while (i < stack->size)
	{
		if (stack->arr[i] > res)
			res = stack->arr[i];
		i ++;
	}
	return (res);
}

int	stack_len(t_stack *stack)
{
	if (stack->top == -1)
		return (0);
	return (stack->size - stack->top);
}

int	top_val(t_stack *stack)
{
	if (stack_len(stack))
		return (stack->arr[stack->top]);
	return (0);
}

int	count_nums_below(t_stack *stack, int target)
{
	int	i;
	int	count;

	if (indexof_target(stack, target) == -1)
		return (-1);
	i = stack->top;
	count = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < target)
			count ++;
		i ++;
	}
	return (count);
}

int	get_num_with_x_below(t_stack *stack, int x)
{
	int	i;

	i = stack->top;
	while (i < stack->size)
	{
		if (count_nums_below(stack, stack->arr[i]) == x)
			return (stack->arr[i]);
		i ++;
	}
	return (0);
}

void	ps_bigsort(const int *arr, int len, t_list **op_lst, const int params[4])
{
	int		*sorted_array;
	t_stack	*stack_a;
	t_stack	*stack_b;
	//int		cache_counter;

	int	pivot = params[0];
	int	pivotb1 = params[1];
	int	pivotb2 = params[2];
	int min_chunk = params[3];

	//ft_printf("PIVOT: %d, PIVOTB1: %d, PIVOTB2: %d, MIN_CHUNK: %d\n", PIVOT, PIVOTB1, PIVOTB2, MIN_CHUNK);

	stack_a = stack_init(arr, len, 'a');
	if (!stack_a)
	{
		//free(arr);
		return ;
	}
	stack_b = stack_init_empty(len, 'b');
	if (!stack_b)
	{
		free(stack_a);
		return ;
	}
	while (stack_len(stack_a) != 1)
	{
		if (min_chunk > stack_len(stack_a) - 1)
			min_chunk = stack_len(stack_a) - 1;
		sorted_array = intarr_bubblesort(stack_a->arr + stack_a->top, stack_len(stack_a));
		if (sorted_array == NULL)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return ;
		}

		int	pivot_a = int_at_percent_in_arr(sorted_array, stack_len(stack_a), pivot);
		int	pivot_b = int_at_percent_in_arr(sorted_array, stack_len(stack_a), (int)((double) pivotb1 / 100.0 * (double) pivotb2));

		/* must keep */
		if (ft_index_of_int(sorted_array, stack_len(stack_a), pivot_a) == 0 && (stack_len(stack_a) > 1))
			pivot_a = sorted_array[1];
		if (ft_index_of_int(sorted_array, stack_len(stack_a), pivot_b) == 0  && (stack_len(stack_a) > 1))
			pivot_b = sorted_array[1];

		if (count_nums_below(stack_a, pivot_a) < min_chunk)
			pivot_a = get_num_with_x_below(stack_a, min_chunk);

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

	for (int k = 0; k < stack_a->size - 1; ++k) {
		stack_a->arr[k] = 0;
	}

	sorted_array = intarr_bubblesort(stack_b->arr + stack_b->top, stack_len(stack_b));
	if (sorted_array == NULL)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return ;
	}

	int cache_size = 0;
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
		//bring_num_to_top(stack_b, sorted_array[index], op_lst);
		//op_p(stack_b, stack_a, op_lst);
		//index --;
	}

	free_stack(stack_a);
	free_stack(stack_b);
	free(sorted_array);
}
