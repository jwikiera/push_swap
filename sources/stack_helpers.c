/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_at_percent_in_arr(const int *arr, int len, int per)
{
	double	one_percent;

	one_percent = (double) len / 100.0;
	return (arr[ft_max_int(0,
				ft_min_int((int)((double) per * one_percent), len - 1))]);
}

int	indexof_target(t_stack *stack, int target)
{
	int	index;

	index = stack->top;
	while (index < stack->size && stack->arr[index] != target)
		index ++;
	if (index == stack->size)
		return (-1);
	return (index);
}

int	stack_has_smaller_num_than(t_stack *stack, int num)
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
		if (indexof_target(stack, target) - stack->top
			<= (stack->size - stack->top) / 2)
			op_r(stack, op_lst);
		else
			op_rr(stack, op_lst);
	}
}

int	stack_len(t_stack *stack)
{
	if (stack->top == -1)
		return (0);
	return (stack->size - stack->top);
}
