/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:46:56 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/11 13:36:27 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*build_instruction(char c1, char c2, char c3)
{
	char	*res;

	if (c3 == 0)
	{
		res = malloc(sizeof(res) * 4);
		if (!res)
			return (NULL);
		res[0] = c1;
		res[1] = c2;
		res[2] = '\n';
		res[3] = 0;
	}
	else
	{
		res = malloc(sizeof(res) * 5);
		if (!res)
			return (NULL);
		res[0] = c1;
		res[1] = c2;
		res[2] = c3;
		res[3] = '\n';
		res[4] = 0;
	}
	return (ft_lstnew(res));
}
