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

void	op_s(t_stack *stack, t_list **op_lst)
{
	int	swp;
	t_list	*node;

	node = build_instruction('s',  stack->type, 0);
	if (node)
		ft_lstadd_back(op_lst, node);
	if (stack->top == -1 || stack->top > stack->size - 2)
		return ;
	swp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top + 1];
	stack->arr[stack->top + 1] = swp;
}

void	op_ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (print)
		ft_putstr_fd("ss\n", 1);
	op_s(stack_a, 0);
	op_s(stack_b, 0);
}

void	op_p(t_stack *stack_src, t_stack *stack_dst, t_list **op_lst)
{
	t_list	*node;

	node = build_instruction('p',  stack_dst->type, 0);
	if (node)
		ft_lstadd_back(op_lst, node);
	if (stack_src->top == -1)
		return ;
	if (stack_dst->top == -1)
		stack_dst->arr[stack_dst->size - 1] = stack_src->arr[stack_src->top];
	else
		stack_dst->arr[stack_dst->top - 1] = stack_src->arr[stack_src->top];
	if (stack_dst->top == -1)
		stack_dst->top = stack_dst->size - 1;
	else
		stack_dst->top --;
	if (stack_src->top == stack_src->size - 1)
		stack_src->top = -1;
	else
		stack_src->top ++;
}

void	op_r(t_stack *stack, t_list **op_lst)
{
	int		swp;
	t_list	*node;

	node = build_instruction('r',  stack->type, 0);
	if (node)
		ft_lstadd_back(op_lst, node);
	if (stack->top == -1)
		return ;
	swp = stack->arr[stack->top];
	shift_up(stack->arr, stack->size);
	stack->arr[stack->size - 1] = swp;
}

void	op_rarb(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (print)
		ft_putstr_fd("rr\n", 1);
	op_r(stack_a, 0);
	op_r(stack_b, 0);
}
