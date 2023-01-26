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

static int	shorten_two(t_list	**node)
{
	char	*ni;
	int		cont;
	t_list	*nextnext;

	cont = 1;
	ni = (*node)->next->content;
	if ((!ft_strncmp((*node)->content, "sa", 2) && !ft_strncmp(ni, "sb", 2))
		|| (!ft_strncmp((*node)->content, "sb", 2) && !ft_strncmp(ni, "sa", 2)))
	{
		free ((*node)->content);
		(*node)->content = malloc(ft_strlen("ss") + 1);
		if (!(*node)->content)
			return (-1);
		ft_strlcpy((*node)->content, "ss\n", ft_strlen("ss\n") + 1);
		nextnext = (*node)->next->next;
		ft_lstdelone((*node)->next, ps_del_node);
		if (nextnext)
			(*node)->next = nextnext;
		cont = 0;
	}
	return (cont);
}

static int	shorten_three(t_list	**node)
{
	char	*ni;
	int		cont;
	t_list	*nextnext;

	cont = 1;
	ni = (*node)->next->content;
	if ((!ft_strncmp((*node)->content, "ra", 2) && !ft_strncmp(ni, "rb", 2))
		|| (!ft_strncmp((*node)->content, "rb", 2) && !ft_strncmp(ni, "ra", 2)))
	{
		free ((*node)->content);
		(*node)->content = malloc(ft_strlen("rr") + 1);
		if (!(*node)->content)
			return (-1);
		ft_strlcpy((*node)->content, "rr\n", ft_strlen("rr\n") + 1);
		nextnext = (*node)->next->next;
		ft_lstdelone((*node)->next, ps_del_node);
		if (nextnext)
			(*node)->next = nextnext;
		cont = 0;
	}
	return (cont);
}

static int	shorten_four(t_list **node)
{
	char	*ni;
	int		cont;
	t_list	*nextnext;

	cont = 1;
	ni = (*node)->next->content;
	if ((!ft_strncmp((*node)->content, "rra", 3) && !ft_strncmp(ni, "rrb", 3))
		|| (!ft_strncmp((*node)->content, "rrb", 3)
			&& !ft_strncmp(ni, "rra", 3)))
	{
		free ((*node)->content);
		(*node)->content = malloc(ft_strlen("rrr") + 1);
		if (!(*node)->content)
			return (-1);
		ft_strlcpy((*node)->content, "rrr\n", ft_strlen("rrr\n") + 1);
		nextnext = (*node)->next->next;
		ft_lstdelone((*node)->next, ps_del_node);
		if (nextnext)
			(*node)->next = nextnext;
		cont = 0;
	}
	return (cont);
}

static int	helper_to_rule_them_all(t_list **node)
{
	int	helper_res;
	int	cont;

	cont = 1;
	helper_res = shorten_two(node);
	if (helper_res == -1)
		return (-1);
	else if (helper_res == 0)
		cont = 0;
	helper_res = shorten_three(node);
	if (helper_res == -1)
		return (-1);
	else if (helper_res == 0)
		cont = 0;
	helper_res = shorten_four(node);
	if (helper_res == -1)
		return (-1);
	else if (helper_res == 0)
		cont = 0;
	return (cont);
}

void	shorten_instructions(t_list **op_lst)
{
	t_list	*node;
	int		cont;
	int		helper_res;

	while (!check_short(*op_lst))
	{
		node = *op_lst;
		cont = 1;
		while (node->next && cont)
		{
			helper_res = helper_to_rule_them_all(&node);
			if (helper_res == -1)
				return ;
			else if (helper_res == 0)
				cont = 0;
			node = node->next;
		}
	}
}
