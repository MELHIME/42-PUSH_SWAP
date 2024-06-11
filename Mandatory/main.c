/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:17:14 by mel-hime          #+#    #+#             */
/*   Updated: 2024/06/11 19:38:32 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_er(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			free(s[i++]);
		free(s);
	}
}

int	range_eq(int n)
{
	int	range;

	if (n <= 50)
		range = 8;
	else if (n <= 100)
		range = 15;
	else
		range = 35;
	return (range);
}

int	find_half(t_list *stack)
{
	int	max;
	int	size;
	int	i;

	max = get_max(stack);
	size = ft_lstsize(stack);
	i = 0;
	while (stack)
	{
		if (stack->index == max)
			break ;
		i++;
		stack = stack->next;
	}
	if (i < size / 2)
		return (1);
	else
		return (2);
	return (0);
}

void	fill_a(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_b))
	{
		if (get_max(*stack_b) == (*stack_b)->index)
			push(stack_b, stack_a, "pa");
		else
		{
			if (find_half(*stack_b) == 1)
				rotate(stack_b, "rb");
			else if (find_half(*stack_b) == 2)
				reverse_rotate(stack_b, "rrb");
		}
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	stack_a = fill_stack(ex_input(argv));
	if (!stack_a)
	{
		write(2, "\033[1;31mError\n\033[0m", 17);
		exit(EXIT_FAILURE);
	}
	if (is_sorted(stack_a))
	{
		ft_lstclear(&stack_a);
		exit(EXIT_SUCCESS);
	}
		
	indexing(stack_a);
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(EXIT_SUCCESS);
}
