/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:06:45 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/09 14:29:22 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while ((*a)->nb != min)
			rx(a, b, A);
		px(a, b, B);
	}
	sorting_three(a, b);
	px(a, b, A);
	px(a, b, A);
}
