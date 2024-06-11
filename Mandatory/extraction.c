/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:17:10 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/01 21:31:04 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ex_input(char *argv[])
{
	int		i;
	char	*str;
	char	**numbers;

	i = 2;
	str = ft_strdup(argv[1]);
	if (!str[0] || !check_empty(argv[1]))
		return (free(str), NULL);
	while (argv[i])
	{
		if (!argv[i][0] || !check_empty(argv[i]))
			return (free(str), NULL);
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	numbers = ft_split(str, ' ');
	free(str);
	return (numbers);
}

t_list	*fill_stack(char **numbers)
{
	t_list	*stack_a;
	int		i;
	int		nb;

	i = 0;
	stack_a = 0;
	if (!numbers)
		return (NULL);
	while (numbers[i])
	{
		if (!check_doubel(stack_a, ft_atoi(numbers[i])) 
			|| !is_number(numbers[i]) || 
			(ft_strlen(numbers[i]) > 1 && !ft_atoi(numbers[i])
				&& !is_0(numbers[i])))
		{
			free_er(numbers);
			ft_lstclear(&stack_a);
			return (NULL);
		}
		nb = ft_atoi(numbers[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(nb));
		i++;
	}
	free_er(numbers);
	return (stack_a);
}

int	is_number(char *s)
{
	int	i;
	int	j;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	j = i;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (j == i)
		return (0);
	return (i == (int)ft_strlen(s));
}

int	check_doubel(t_list *stack_a, int n)
{
	while (stack_a != NULL)
	{
		if (stack_a->content == n)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if ((int)ft_strlen(str) == i)
		return (0);
	else
		return (1);
}
