/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:22:05 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/07 09:22:05 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char *opr)
{
	int	r;

	if (ft_lstsize(stack) >= 2)
	{
		r = stack->content;
		stack->content = stack->next->content;
		stack->next->content = r;
	}
	if (ft_strncmp(opr, "sa", 2) == 0)
		write(1, "\033[1;33msa\n\033[0m", 14);
	else if (ft_strncmp(opr, "sb", 2) == 0)
		write(1, "\033[1;33msb\n\033[0m", 14);
}

void	push(t_list **src, t_list **dest, char *opr)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
	if (ft_strncmp(opr, "pa", 2) == 0)
		write(1, "\033[1;33mpa\n\033[0m", 14);
	else if (ft_strncmp(opr, "pb", 2) == 0)
		write(1, "\033[1;33mpb\n\033[0m", 14);
}

void	rotate(t_list **stack, char *opr)
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
	if (ft_strncmp(opr, "ra", 2) == 0)
		write(1, "\033[1;33mra\n\033[0m", 14);
	else if (ft_strncmp(opr, "rb", 2) == 0)
		write(1, "\033[1;33mrb\n\033[0m", 14);
}

void	reverse_rotate(t_list **stack, char *opr)
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
	if (ft_strncmp(opr, "rra", 3) == 0)
		write(1, "\033[1;33mrra\n\033[0m", 15);
	else if (ft_strncmp(opr, "rrb", 3) == 0)
		write(1, "\033[1;33mrrb\n\033[0m", 15);
}
