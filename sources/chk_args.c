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

static int	count_int_in_arr(int theint, const int *arr, int size)
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

static int	ret_freeintarr(int *int_arr, int ret)
{
	free(int_arr);
	return (ret);
}

int	chk_dupes_in_one_arg(char **split_res, size_t wordcount)
{
	size_t	i;
	int		*int_arr;

	int_arr = one_arg_to_intarray(split_res, wordcount);
	if (!int_arr)
		return (0);
	i = 0;
	while (i < wordcount)
	{
		if (count_int_in_arr(int_arr[i], int_arr, wordcount) > 1)
			return (ret_freeintarr(int_arr, 0));
		i ++;
	}
	return (ret_freeintarr(int_arr, 1));
}

int	chk_one_arg(char *argv[])
{
	char	**split_res;
	size_t	i;
	size_t	word_count;

	split_res = ft_split(argv[1], ' ');
	if (!split_res)
		return (0);
	i = 0;
	word_count = count_words(argv[1], ' ');
	while (i < word_count)
	{
		if (!ft_str_is_int(split_res[i], 0))
		{
			ft_free_split(split_res, word_count);
			return (0);
		}
		i ++;
	}
	return (chk_dupes_in_one_arg(split_res, word_count));
}

int	chk_args(int argc, char *argv[])
{
	int	i;
	int	*int_arr;

	if (argc == 2)
		return (chk_one_arg(argv));
	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_int(argv[i], 0))
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
			return (ret_freeintarr(int_arr, 0));
		i ++;
	}
	return (ret_freeintarr(int_arr, 1));
}
