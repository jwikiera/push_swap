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

/* Merge sort pivot location as percentage of the stack (50 will be the middle of the stack) */
# ifndef PIVOT
#  define PIVOT 19
# endif

# ifndef PIVOTB1
#  define PIVOTB1 34
# endif

# ifndef PIVOTB2
#  define PIVOTB2 31
# endif

# ifndef MIN_CHUNK
#  define MIN_CHUNK 10
# endif

int		chk_args(int argc, char *argv[]);
int		*args_to_intarray(int argc, char *argv[]);
int		*one_arg_to_intarray(char **split_res, size_t word_count);
void	sort_two(int *arr);
void	sort_three(int *arr);
void	sort_five(int *arr, int len, t_list **op_lst);
void	ps_mysort(int *arr, int len, t_list **op_lst);
void	ps_bigsort(const int *arr, int len, t_list **op_lst, const int params[4]);
int		*intarr_bubblesort(const int *arr, int len);
void	shorten_instructions(t_list **op_lst);
int		count_instructions(t_list *op_lst);

typedef struct s_stack
{
	int		size;
	int		top;
	int		*arr;
	char	type;
}	t_stack;

t_stack	*stack_init(const int *arr, int size, char type);
t_stack	*stack_init_empty(int size, char type);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
t_list	*build_instruction(char c1, char c2, char c3);

void	op_s(t_stack *stack, t_list **op_lst);
void	op_p(t_stack *stack_src, t_stack *stack_dst, t_list **op_lst);
void	op_r(t_stack *stack, t_list **op_lst);
void	op_rr(t_stack *stack, t_list **op_lst);

void	op_ss(t_stack *stack_a, t_stack *stack_b, int print);
void	op_rarb(t_stack *stack_a, t_stack *stack_b, int print);
void	op_rrr(t_stack *stack_a, t_stack *stack_b, int print);

void	shift_down(int *arr, int len);
void	shift_up(int *arr, int len);

#endif
