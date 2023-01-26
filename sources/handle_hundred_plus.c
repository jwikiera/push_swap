/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hundred_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:48:31 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/28 15:48:32 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_ops(int argc)
{
	if (argc < 102)
		return (699);
	return (5499);
}

static	void	handle_two(t_list **op_lst, int *array, int argc, int *params)
{
	params[0] = 19;
	params[3] -= 10;
	while (count_instructions(*op_lst) > get_max_ops(argc) && params[3] < 25)
	{
		ft_lstclear(op_lst, ps_del_node);
		*op_lst = NULL;
		ps_bigsort(array, argc - 1, op_lst, params);
		shorten_instructions(op_lst);
		params[3]++;
	}
	params[0] = 19;
	params[3] = 10;
	params[1] -= 10;
	while (count_instructions(*op_lst) > get_max_ops(argc) && params[1] < 42)
	{
		ft_lstclear(op_lst, ps_del_node);
		*op_lst = NULL;
		ps_bigsort(array, argc - 1, op_lst, params);
		shorten_instructions(op_lst);
		params[1]++;
	}
}

void	handle_hundred_plus(t_list **op_lst, int *array, int argc)
{
	int	params[4];

	params[0] = PIVOT;
	params[1] = PIVOTB1;
	params[2] = PIVOTB2;
	params[3] = MIN_CHUNK;
	ps_bigsort(array, argc - 1, op_lst, params);
	shorten_instructions(op_lst);
	params[0] -= 10;
	while (count_instructions(*op_lst) > get_max_ops(argc) && params[0] < 30)
	{
		ft_lstclear(op_lst, ps_del_node);
		*op_lst = NULL;
		ps_bigsort(array, argc - 1, op_lst, params);
		shorten_instructions(op_lst);
		params[0]++;
	}
	handle_two(op_lst, array, argc, params);
}
