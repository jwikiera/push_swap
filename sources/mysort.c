/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_mysort(int *arr, int len)
{
	int		*sorted_array;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	print_stack(stack_a);
	print_stack(stack_b);
	op_r(stack_a, 1);
	print_stack(stack_a);
	print_stack(stack_b);
	sorted_array = intarr_bubblesort(arr, len);
	if (sorted_array == NULL)
	{
		free(stack_b);
		return ;
	}
	ft_printf("sorted\n");

	free(stack_b);
	free(sorted_array);
}
