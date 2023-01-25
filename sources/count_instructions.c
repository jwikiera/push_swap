/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_instructions(t_list *op_lst)
{
	int		res;
	t_list	*node;

	res = 0;
	node = op_lst;
	while (node)
	{
		res ++;
		node = node->next;
	}
	return (res);
}
