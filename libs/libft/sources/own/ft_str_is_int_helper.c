/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwikiera <jwikiera@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2022/10/20 11:12:18 by jwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_has_multiple_signs(const char *str)
{
	char	*trimmed;

	trimmed = ft_blank_trim(str);
	if (!trimmed)
		return (0);
	if (ft_char_cnt(trimmed, '-') > 1 || ft_char_cnt(trimmed, '+') > 1
		|| (ft_char_cnt(trimmed, '-') >= 1 && ft_char_cnt(trimmed, '+') >= 1))
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

int	ft_has_syms_after_nums(const char *str)
{
	char	*trimmed;
	size_t	after_char_index;

	trimmed = ft_blank_trim(str);
	if (!trimmed)
		return (0);
	after_char_index = 0;
	while (trimmed[after_char_index] && !ft_isdigit(trimmed[after_char_index]))
		after_char_index ++;
	while (ft_isdigit(trimmed[after_char_index]))
		after_char_index ++;
	if (ft_strlen(trimmed + after_char_index) > 0)
	{
		free (trimmed);
		return (1);
	}
	free (trimmed);
	return (0);
}
