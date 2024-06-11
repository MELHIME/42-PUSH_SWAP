/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:46:29 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/01 13:47:18 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

t_list	*fill_stack(char **numbers);
int		check_empty(char *str);
char	**ex_input(char *argv[]);
void	free_er(char **s);
int		range_eq(int n);
int		is_0(char *s);
int		check_doubel(t_list *stack_a, int n);
int		is_number(char *s);
void	swap(t_list *stack, char *opr);
void	push(t_list **src, t_list **dest, char *opr);
void	rotate(t_list **stack, char *opr);
void	reverse_rotate(t_list **stack, char *opr);
int		is_sorted(t_list *stack_a);
void	indexing(t_list *stack);
void	sort3(t_list **stack);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);
void	sort_over(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
int		which_half(t_list *stack);
int		find_min(t_list *stack_);
int		is_min_up(t_list *stack_, int n);
void	fill_a(t_list **stack_a, t_list **stack_b);
int		find_half(t_list *stack_);
int		get_max(t_list *stack_);

#endif
