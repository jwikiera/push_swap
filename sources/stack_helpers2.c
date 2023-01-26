/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
