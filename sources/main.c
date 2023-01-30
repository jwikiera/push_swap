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

static int	handle_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	free_arr(int *arr)
{
	free(arr);
	return (0);
}

static void	handle_helper(int argc, int *array, t_list **op_lst)
{
	if (argc == 3)
		sort_two(array);
	else if (argc == 4)
		sort_three(array);
	else if (argc < 7)
		sort_five(array, argc - 1, op_lst);
	else
		handle_hundred_plus(op_lst, array, argc);
}

int	main(int argc, char *argv[])
{
	int		*array;
	t_list	*op_lst;

	op_lst = NULL;
	if (argc < 2)
		exit(0);
	if (!chk_args(argc, argv))
		exit(handle_exit());
	array = args_to_intarray(argc, argv);
	if (!array)
		return (1);
	if (argc == 2)
		argc = count_words(argv[1], ' ') + 1;
	if (ft_array_is_sorted(array, argc - 1))
	{
		ps_cleanup(&op_lst, array);
		exit(0);
	}
	if (argc == 1 || argc == 2)
		exit(free_arr(array));
	else
		handle_helper(argc, array, &op_lst);
	print_instructions(op_lst);
	ps_cleanup(&op_lst, array);
	return (0);
}
