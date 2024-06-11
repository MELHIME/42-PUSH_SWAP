/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:01:45 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/02 12:40:17 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list *stack)
{
	int	r;

	if (ft_lstsize(stack) >= 2)
	{
		r = stack->content;
		stack->content = stack->next->content;
		stack->next->content = r;
	}
}

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack) <= 1)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	(*stack) = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	last = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}
