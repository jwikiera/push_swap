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

/*
	Sorting 5 values:
 	- no more than 12 actions.

 	Sorting 100 values:
    - 5 points for less than 700 actions

	Sorting 500 values:
    - 5 points for less than 5500 actions
*/

int	main(int argc, char *argv[])
{
	int	*array;

	if (argc < 2)
		exit(0);
	if (!chk_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	array = args_to_intarray(argc, argv);
	if (argc == 2)
		argc = count_words(argv[1], ' ') + 1;
	ft_printf("arg amount: %d\n", argc);
	if (argc == 2)
	{
		free(array);
		exit(0);
	}
	else if (argc == 3)
		sort_two(array);
	else if (argc == 4)
		sort_three(array);
	else if (argc < 7)
		sort_five(array, argc - 1);
	else if (argc < 102)
		sort_hundred(array, argc - 1);
	else
		sort_fivehundred(array, argc - 1);
	free(array);
	return (0);
}
