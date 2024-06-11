/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:22:45 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/04 12:38:46 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		swap(*stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content)
	{
		if ((*stack)->content > (*stack)->next->next->content)
			rotate(stack, "ra");
		else
			swap(*stack, "sa");
	}
	else if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		if ((*stack)->content < (*stack)->next->next->content)
		{
			swap(*stack, "sa");
			rotate(stack, "ra");
		}
		else
			reverse_rotate(stack, "rra");
	}
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (1)
	{
		if (is_min_up(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b, "pb");
			sort3(stack_a);
			push(stack_b, stack_a, "pa");
			return ;
		}
		else
		{
			if (which_half(*stack_a) == 1)
				rotate(stack_a, "ra");
			else if (which_half(*stack_a) == 2)
				reverse_rotate(stack_a, "rra");
		}
	}
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (1)
	{
		if (is_min_up(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b, "pb");
			sort4(stack_a, stack_b);
			push(stack_b, stack_a, "pa");
			return ;
		}
		else
		{
			if (which_half(*stack_a) == 1)
				rotate(stack_a, "ra");
			else if (which_half(*stack_a) == 2)
				reverse_rotate(stack_a, "rra");
		}
	}
}

void	sort_over(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = range_eq(ft_lstsize(*stack_a));
	while ((*stack_a))
	{
		if ((*stack_a)->index <= range && (*stack_a)->index >= i)
		{
			push(stack_a, stack_b, "pb");
			i++;
			range++;
		}
		else if ((*stack_a)->index < i)
		{
			push(stack_a, stack_b, "pb");
			rotate(stack_b, "rb");
			i++;
			range++;
		}
		else
			rotate(stack_a, "ra");
	}
	fill_a(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 5)
		sort_over(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) == 2)
	{
		swap(*stack_a, "sa");
	}
}
