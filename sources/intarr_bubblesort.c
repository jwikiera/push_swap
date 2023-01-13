/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intarr_bubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(const int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i ++;
	}
	return (1);
}

int	*intarr_bubblesort(const int *arr, int len)
{
	int	*res;
	int	swp;
	int	i;

	res = malloc(len * sizeof(*res));
	if (!res)
		return (NULL);
	ft_memcpy(res, arr, len * sizeof(*res));
	while (!is_sorted(res, len))
	{
		i = 0;
		while (i < len - 1)
		{
			if (res[i] > res[i + 1])
			{
				swp = res[i];
				res[i] = res[i + 1];
				res[i + 1] = swp;
			}
			i ++;
		}
	}
	return (res);
}
