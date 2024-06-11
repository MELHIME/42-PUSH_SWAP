/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:22:10 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/13 10:08:49 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	is_sorted(t_list *stack_a)
{
	int	t;
	if (!stack_a)
		return (0);
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

int	verify_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_strncmp("sa\n", move, ft_strlen(move)))
		return (swap(*stack_a), 1);
	else if (!ft_strncmp("sb\n", move, ft_strlen(move)))
		return (swap(*stack_b), 1);
	else if (!ft_strncmp("pa\n", move, ft_strlen(move)))
		return (push(stack_b, stack_a), 1);
	else if (!ft_strncmp("pb\n", move, ft_strlen(move)))
		return (push(stack_a, stack_b), 1);
	else if (!ft_strncmp("ra\n", move, ft_strlen(move)))
		return (rotate(stack_a), 1);
	else if (!ft_strncmp("rb\n", move, ft_strlen(move)))
		return (rotate(stack_b), 1);
	else if (!ft_strncmp("rra\n", move, ft_strlen(move)))
		return (reverse_rotate(stack_a), 1);
	else if (!ft_strncmp("rrb\n", move, ft_strlen(move)))
		return (reverse_rotate(stack_b), 1);
	else if (!ft_strncmp("ss\n", move, ft_strlen(move)))
		return (ss(*stack_a, *stack_b), 1);
	else if (!ft_strncmp("rr\n", move, ft_strlen(move)))
		return (rr(stack_a, stack_b), 1);
	else if (!ft_strncmp("rrr\n", move, ft_strlen(move)))
		return (rrr(stack_a, stack_b), 1);
	return (0);
}

void	check_moves(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0); 
	while (move)
	{
		if (!verify_move(stack_a, stack_b, move))
		{
			free(move);
			write(2, "\033[1;31mError\n\033[0m", 17);
			exit(EXIT_FAILURE);
		}
		free(move);
		move = get_next_line(0);
	}
	if (is_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
		write(1, "\033[1;32mOK\n\033[0m", 14);
	else
		write(1, "\033[1;31mKO\n\033[0m", 14);
	return ;
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	stack_a = fill_stack(ex_input(argv));
	if (!stack_a)
	{
		write(2, "\033[1;31mError\n\033[0m", 17);
		exit(EXIT_FAILURE);
	}
	check_moves(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(EXIT_SUCCESS);
}
