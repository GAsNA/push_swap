/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:09 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/04 21:28:34 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	aff_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%i | ", stack->nb);
		stack = stack->next;
	}
	printf("\n");
}*/

int	len_stack(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*ft_list_last(t_stack *stack)
{
	t_stack	*last;

	while (stack)
	{
		last = stack;
		stack = stack->next;
	}
	return (last);
}

t_stack	*ft_stackdup(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*next;

	dup = create_elem_list(stack->nb);
	next = dup;
	stack = stack->next;
	while (stack)
	{
		next->next = create_elem_list(stack->nb);
		next = next->next;
		stack = stack->next;
	}
	return (dup);
}

int	*stack_to_tab(t_stack **a)
{
	t_stack	*tmp;
	int		*tab;
	int		i;

	tab = malloc(len_stack(*a) * sizeof(int));
	if (!tab)
		return (0);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}
