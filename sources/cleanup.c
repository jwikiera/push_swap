/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:48:31 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/28 15:48:32 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_cleanup(t_list **op_lst, int *arr)
{
	if (op_lst)
		ft_lstclear(op_lst, ps_del_node);
	if (arr)
		free(arr);
}
