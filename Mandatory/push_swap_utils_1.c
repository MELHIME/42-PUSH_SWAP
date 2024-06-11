/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:15:29 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/04 12:59:12 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_0(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (i == (int)ft_strlen(s))
		return (1);
	else
		return (0);
}

int	which_half(t_list *stack)
{
	int	s;
	int	min;
	int	i;

	min = find_min(stack);
	s = ft_lstsize(stack);
	i = 0;
	while (stack)
	{
		if (stack->index == min)
			break ;
		i++;
		stack = stack->next;
	}
	if (i <= s / 2)
		return (1);
	else
		return (2);
}
