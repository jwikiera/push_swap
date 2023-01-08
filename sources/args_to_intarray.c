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

/* This functions assumes the args are valid ints */
int	*args_to_intarray(int argc, char *argv[])
{
	int	i;
	int	*res;

	if (argc == 2)
		return (one_arg_to_intarray(
				ft_split(argv[1], ' '),
				count_words(argv[1], ' ')));
	res = malloc(sizeof(*res) * (argc - 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		res[i] = ft_atoi(argv[i + 1]);
		i ++;
	}
	return (res);
}

int	*one_arg_to_intarray(char **split_res, size_t word_count)
{
	size_t	i;
	int		*res;

	if (!split_res)
		return (NULL);
	res = malloc(sizeof(*res) * (word_count));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		res[i] = ft_atoi(split_res[i]);
		i ++;
	}
	return (res);
}
