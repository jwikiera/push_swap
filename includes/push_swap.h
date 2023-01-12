/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:46:56 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/11 13:36:27 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifdef LINUX
# else
# endif

# include "stdlib.h"
# include "stdio.h"
# include "math.h"

# include <libft.h>
# include <ft_printf.h>

int		chk_args(int argc, char *argv[]);
int		*args_to_intarray(int argc, char *argv[]);
int		*one_arg_to_intarray(char **split_res, size_t word_count);
void	sort_two(const int *arr);
void	sort_three(const int *arr);
void	sort_five(const int *arr, size_t len);
void	sort_hundred(const int *arr, size_t len);
void	sort_fivehundred(const int *arr, size_t len);
void	ps_mysort(int *arr, size_t len);
int		*intarr_bubblesort(const int *arr, size_t len);

typedef struct s_stack
{
	size_t	size;
	size_t	top;
	int		*arr;
	char	type;
}	t_stack;

t_stack	*stack_init(int *arr, size_t size, size_t top, char type);
t_stack	*stack_init_empty(size_t size, size_t top, char type);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

void	op_s(t_stack *stack, int print);
void	op_ss(t_stack *stack_a, t_stack *stack_b, int print);
void	op_p(t_stack *stack_src, t_stack *stack_dst, int print);
void	op_r(t_stack *stack, int print);
void	op_rarb(t_stack *stack_a, t_stack *stack_b, int print);
void	op_rr(t_stack *stack, int print);
void	op_rrr(t_stack *stack_a, t_stack *stack_b, int print);

void	shift_down(int *arr, size_t len);
void	shift_up(int *arr, size_t len);

#endif
