/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorten_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_node(void *content)
{
	free(content);
}

int	check_short(t_list *op_lst)
{
	t_list	*node;
	char	*ci;
	char	*ni;

	node = op_lst;
	while (node->next)
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

void	shorten_instructions(t_list **op_lst)
{
	t_list	*node;
	t_list	*nextnext;
	//char	*ci;
	char	*ni;
	int		cont;

	while (!check_short(*op_lst))
	{
		node = *op_lst;
		cont = 1;
		while (node->next && cont)
		{
			//ci = node->content;
			ni = node->next->content;
			if ((!ft_strncmp(node->content, "sa", 2) && !ft_strncmp(ni, "sb", 2))
				|| (!ft_strncmp(node->content, "sb", 2) && !ft_strncmp(ni, "sa", 2)))
			{
				free (node->content);
				node->content = malloc(ft_strlen("ss") + 1);
				if (!node->content)
					return ;
				ft_strlcpy(node->content, "ss\n", ft_strlen("ss\n") + 1);
				nextnext = node->next->next;
				ft_lstdelone(node->next, delete_node);
				if (nextnext)
					node->next = nextnext;
				cont = 0;
			}
			if ((!ft_strncmp(node->content, "ra", 2) && !ft_strncmp(ni, "rb", 2))
				|| (!ft_strncmp(node->content, "rb", 2) && !ft_strncmp(ni, "ra", 2)))
			{
				free (node->content);
				node->content = malloc(ft_strlen("rr") + 1);
				if (!node->content)
					return ;
				ft_strlcpy(node->content, "rr\n", ft_strlen("rr\n") + 1);
				nextnext = node->next->next;
				ft_lstdelone(node->next, delete_node);
				if (nextnext)
					node->next = nextnext;
				cont = 0;
			}
			if ((!ft_strncmp(node->content, "rra", 3) && !ft_strncmp(ni, "rrb", 3))
				|| (!ft_strncmp(node->content, "rrb", 3) && !ft_strncmp(ni, "rra", 3)))
			{
				free (node->content);
				node->content = malloc(ft_strlen("rrr") + 1);
				if (!node->content)
					return ;
				ft_strlcpy(node->content, "rrr\n", ft_strlen("rrr\n") + 1);
				nextnext = node->next->next;
				ft_lstdelone(node->next, delete_node);
				if (nextnext)
					node->next = nextnext;
				cont = 0;
			}
			node = node->next;
		}
	}
}
