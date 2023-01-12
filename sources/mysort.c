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

void	ps_mysort(const int *arr, size_t len)
{
	int	*sorted_array;
	int	*stack_b;

	stack_b = malloc(len * sizeof(*stack_b));
	if (!stack_b)
		return ;
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
