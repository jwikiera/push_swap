/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_int_in_arr(int theint, int *arr, int size)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		if (arr[i] == theint)
			counter ++;
		i ++;
	}
	return (counter);
}

int	chk_args(int argc, char *argv[])
{
	int	i;
	int	*int_arr;

	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_int(argv[i]))
			return (0);
		i ++;
	}
	int_arr = args_to_intarray(argc, argv);
	if (!int_arr)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (count_int_in_arr(int_arr[i], int_arr, argc - 1) > 1)
		{
			free(int_arr);
			return (0);
		}
		i ++;
	}
	free(int_arr);
	return (1);
}
