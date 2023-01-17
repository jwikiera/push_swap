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
	if (arr[1] > arr[0] && arr[2] > arr[0] && arr[1] > arr[2])
		ft_putstr_fd("rra\nsa\n", 1);
	else if (arr[1] < arr[0] && arr[2] > arr[0] && arr[2] > arr[1])
		ft_putstr_fd("sa\n", 1);
	else if (arr[1] > arr[0] && arr[2] < arr[0] && arr[2] < arr[1])
		ft_putstr_fd("rra\n", 1);
	else if (arr[1] < arr[0] && arr[2] < arr[0] && arr[2] > arr[1])
		ft_putstr_fd("ra\n", 1);
	else if (arr[1] < arr[0] && arr[2] < arr[0] && arr[2] < arr[1])
		ft_putstr_fd("ra\nsa\n", 1);
	free(arr);
}
