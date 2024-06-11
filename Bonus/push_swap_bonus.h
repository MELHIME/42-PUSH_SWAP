/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:29:41 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/02 12:59:58 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

void	free_er(char **s);
t_list	*fill_stack(char **numbers);
char	**ex_input(char *argv[]);
int		is_sorted(t_list *stack_a);
void	check_moves(t_list **stack_a, t_list **stack_b);
int		is_number(char *s);
int		check_doubel(t_list *stack_a, int n);
int		check_empty(char *str);
int		verify_move(t_list **stack_a, t_list **stack_b, char *move);
void	swap(t_list *stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	ss(t_list *stack_a, t_list *stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		is_0(char *s);

#endif