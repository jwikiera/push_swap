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
