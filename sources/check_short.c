/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_short(t_list *op_lst)
{
	t_list	*node;
	char	*ci;
	char	*ni;

	node = op_lst;
	while (node && node->next)
	{
		ci = node->content;
		ni = node->next->content;
		if ((!ft_strncmp(ci, "sa", 2) && !ft_strncmp(ni, "sb", 2))
			|| (!ft_strncmp(ci, "sb", 2) && !ft_strncmp(ni, "sa", 2)))
			return (0);
		if ((!ft_strncmp(ci, "ra", 2) && !ft_strncmp(ni, "rb", 2))
			|| (!ft_strncmp(ci, "rb", 2) && !ft_strncmp(ni, "ra", 2)))
			return (0);
		if ((!ft_strncmp(ci, "rra", 3) && !ft_strncmp(ni, "rrb", 3))
			|| (!ft_strncmp(ci, "rrb", 3) && !ft_strncmp(ni, "rra", 3)))
			return (0);
		node = node->next;
	}
	return (1);
}
