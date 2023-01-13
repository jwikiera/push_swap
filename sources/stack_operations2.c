/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rr(t_stack *stack, int print)
{
	int	swp;

	if (print)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(stack->type, 1);
		ft_putchar_fd('\n', 1);
	}
	if (stack->top == -1)
		return ;
	swp = stack->arr[stack->size - 1];
	shift_down(stack->arr, stack->size);
	stack->arr[stack->top] = swp;
}

void	op_rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (print)
		ft_putstr_fd("rrr\n", 1);
	op_rr(stack_a, 0);
	op_rr(stack_b, 0);
}
