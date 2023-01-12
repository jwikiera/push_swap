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

void	shift_down(int *arr, size_t len)
{
	size_t	i;
	int		swp;
	int		swp2;

	i = 0;
	swp = 0;
	while (i < len - 1)
	{
		swp2 = arr[i];
		arr[i] = swp;
		swp = arr[i + 1];
		arr[i + 1] = swp2;
		i ++;
	}
}

void	shift_up(int *arr, size_t len)
{
	size_t	i;
	int		swp;
	int		swp2;

	i = len - 1;
	swp = 0;
	while (i > 1)
	{
		swp2 = arr[i];
		arr[i] = swp;
		swp = arr[i - 1];
		arr[i - 1] = swp2;
		i --;
	}
}
