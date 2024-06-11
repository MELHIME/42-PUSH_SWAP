/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:17:02 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/04 12:52:51 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	int	t;

	t = stack_a->content;
	while (stack_a->next)
	{
		if (stack_a->next->content < t)
			return (0);
		stack_a = stack_a->next;
		t = stack_a->content;
	}
	return (1);
}

void	indexing(t_list *stack)
{
	t_list	*tmp;
	t_list	*head;

	head = stack;
	while (head)
	{
		head->index = 0;
		tmp = stack;
		while (tmp)
		{
			if (tmp->content < head->content)
				head->index++;
			tmp = tmp->next;
		}
		head = head->next;
	}
}

int	is_min_up(t_list *stack, int n)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min == n);
}

int	find_min(t_list *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
