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

#include "checker.h"

static int	handle_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	valid_instruction(const char *instruction)
{
	return (!ft_strncmp(instruction, "sa\n", ft_strlen("sa\n"))
		|| !ft_strncmp(instruction, "sb\n", ft_strlen("sb\n"))
		|| !ft_strncmp(instruction, "ss\n", ft_strlen("ss\n"))
		|| !ft_strncmp(instruction, "pa\n", ft_strlen("pa\n"))
		|| !ft_strncmp(instruction, "pb\n", ft_strlen("pb\n"))
		|| !ft_strncmp(instruction, "ra\n", ft_strlen("ra\n"))
		|| !ft_strncmp(instruction, "rb\n", ft_strlen("rb\n"))
		|| !ft_strncmp(instruction, "rr\n", ft_strlen("rr\n"))
		|| !ft_strncmp(instruction, "rra\n", ft_strlen("rra\n"))
		|| !ft_strncmp(instruction, "rrb\n", ft_strlen("rrb\n"))
		|| !ft_strncmp(instruction, "rrr\n", ft_strlen("rrr\n")));
}

static int	init_stacks(t_stack **stack_a,
				t_stack **stack_b, const int *arr, int len)
{
	*stack_a = stack_init(arr, len, 'a');
	if (!*stack_a)
		return (0);
	*stack_b = stack_init_empty(len, 'b');
	if (!*stack_b)
	{
		free(stack_a);
		return (0);
	}
	return (1);
}

static void	helper(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!valid_instruction(input))
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		else
			perform_op(stack_a, stack_b, input);
		free(input);
		input = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;

	if (argc < 2)
		exit(0);
	if (!chk_args(argc, argv))
		exit(handle_exit());
	array = args_to_intarray(argc, argv);
	if (!array)
		return (1);
	if (argc == 2)
		argc = count_words(argv[1], ' ') + 1;
	argc --;
	if (!init_stacks(&stack_a, &stack_b, array, argc))
		return (1);
	helper(stack_a, stack_b);
	if (stack_a->top == 0 && ft_array_is_sorted(stack_a->arr, stack_a->size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	checker_cleanup(array, stack_a, stack_b);
	return (0);
}
