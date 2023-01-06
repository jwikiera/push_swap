/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *arr)
{
	int	swp;

	if (arr[0] >= arr[1] && arr[0] >= arr[2])
	{
		ft_putstr_fd("ra\n", 1);
		swp = arr[0];
		arr[0] = arr[2];
		arr[2] = swp;
	} else if (arr[1] >= arr[2])
	{
		ft_putstr_fd("ra\n", 1);
		swp = arr[1];
		arr[1] = arr[2];
		arr[2] = swp;
	}
	sort_two(arr);
}
