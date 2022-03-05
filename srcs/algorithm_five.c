/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:06:45 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/05 05:25:25 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_rx(t_stack **a, t_stack **b, int min)
{
	t_stack	*tmp;
	int		i;

	tmp = (*a);
	i = 0;
	while (tmp->nb != min)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= len_stack(*a) / 2)
		while ((*a)->nb != min)
			rx(a, b, A);
	else
		while ((*a)->nb != min)
			rrx(a, b, A);
}

void	sorting_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		n;
	int		min;

	n = -1;
	while (++n < 2)
	{
		min = (*a)->nb;
		tmp = (*a)->next;
		while (tmp)
		{
			if (min > tmp->nb)
				min = tmp->nb;
			tmp = tmp->next;
		}
		choose_rx(a, b, min);
		px(a, b, B);
	}
	if (!is_sort(a))
		sorting_three(a, b);
	px(a, b, A);
	px(a, b, A);
}
