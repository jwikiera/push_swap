/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_shifts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Moves all numbers in an array one slot to the right */
void	shift_down(int *arr, int len)
{
	int	i;
	int	swp[2];
	int	swp_index;

	i = 0;
	swp[0] = 0;
	swp_index = 0;
	while (i < len)
	{
		swp[(swp_index + 1) % 2] = arr[i];
		arr[i] = swp[swp_index % 2];
		i ++;
		swp_index ++;
	}
}

/* Moves all numbers in an array one slot to the left */
void	shift_up(int *arr, int len)
{
	int	i;
	int	swp[2];
	int	swp_index;

	i = len - 1;
	swp[0] = 0;
	swp_index = 0;
	while (i >= 0)
	{
		swp[(swp_index + 1) % 2] = arr[i];
		arr[i] = swp[swp_index % 2];
		i --;
		swp_index ++;
	}
}
