/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:09 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/10 11:51:13 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void aff_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%i | ", stack->nb);
        stack = stack->next;
    }
    printf("\n");
}

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
