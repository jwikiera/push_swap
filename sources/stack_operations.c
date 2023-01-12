/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, int print)
{
	int	swp;

	if (print)
	{
		ft_putchar_fd('s' ,1);
		ft_putchar_fd(stack->type ,1);
		ft_putchar_fd('\n' ,1);
	}
	if (stack->top < stack->size - 2)
		return ;
	swp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top + 1];
	stack->arr[stack->top + 1] = swp;
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (print)
		ft_putstr_fd("ss\n", 1);
	s(stack_a, 0);
	s(stack_b, 0);
}

void	p(t_stack *stack_src, t_stack *stack_dst, int print)
{
	if (print)
	{

	}
}
