/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	perform_op(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (!ft_strncmp(op, "sa\n", ft_strlen("sa\n")))
		op_s(stack_a, NULL);
	else if (!ft_strncmp(op, "sb\n", ft_strlen("sb\n")))
		op_s(stack_b, NULL);
	else if (!ft_strncmp(op, "ss\n", ft_strlen("ss\n")))
		op_ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pa\n", ft_strlen("pa\n")))
		op_p(stack_b, stack_a, NULL);
	else if (!ft_strncmp(op, "pb\n", ft_strlen("pb\n")))
		op_p(stack_a, stack_b, NULL);
	else if (!ft_strncmp(op, "ra\n", ft_strlen("ra\n")))
		op_r(stack_a, NULL);
	else if (!ft_strncmp(op, "rb\n", ft_strlen("rb\n")))
		op_r(stack_b, NULL);
	else if (!ft_strncmp(op, "rr\n", ft_strlen("rr\n")))
		op_rarb(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "rra\n", ft_strlen("rra\n")))
		op_rr(stack_a, NULL);
	else if (!ft_strncmp(op, "rrb\n", ft_strlen("rrb\n")))
		op_rr(stack_b, NULL);
	else if (!ft_strncmp(op, "rrr\n", ft_strlen("rrr\n")))
		op_rrr(stack_a, stack_b, 0);
}
