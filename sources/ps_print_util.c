/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	ft_printf("Stack %c (%p), size: %d, top: %d, arr: [",
		stack->type, stack, stack->size, stack->top);
	i = 0;
	while (i < stack->size)
	{
		if (i == stack->top)
			ft_printf("@%d", stack->arr[i]);
		else
			ft_printf("%d", stack->arr[i]);
		if (i < stack->size - 1)
			ft_printf(", ");
		i ++;
	}
	ft_printf("]\n");
}

void	print_instructions(t_list *op_lst)
{
	t_list	*lst_ptr;

	lst_ptr = op_lst;
	while (lst_ptr != NULL)
	{
		ft_printf("%s", lst_ptr->content);
		lst_ptr = lst_ptr->next;
	}
}
