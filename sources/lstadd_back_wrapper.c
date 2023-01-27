/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_wrapper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back_wrapper(t_list **lst, t_list *new)
{
	if (lst)
		ft_lstadd_back(lst, new);
}
