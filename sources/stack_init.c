/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int *arr, int size, char type)
{
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->arr = arr;
	res->size = size;
	res->top = 0;
	res->type = type;
	return (res);
}

t_stack	*stack_init_empty(int size, char type)
{
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->arr = ft_calloc(1, sizeof(int) * size);
	//res->arr = malloc(sizeof(int) * size);
	if (!res->arr)
	{
		free(res);
		return (NULL);
	}
	res->size = size;
	res->top = -1;
	res->type = type;
	return (res);
}

void	free_stack(t_stack *stack)
{
	if (stack->arr)
		free(stack->arr);
	free(stack);
}
