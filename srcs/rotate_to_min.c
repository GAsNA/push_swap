/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:53:26 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/01 13:55:46 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_and_pos(t_stack **a, int *min, int *i)
{
	t_stack	*tmp;

	*min = (*a)->nb;
	tmp = (*a)->next;
	while (tmp)
	{
		if (*min > tmp->nb)
			*min = tmp->nb;
		tmp = tmp->next;
	}
	tmp = (*a);
	*i = -1;
	while (tmp->nb != *min && ++(*i) < len_stack(*a))
		tmp = tmp->next;
}

void	rotate_to_min(t_stack **a, t_stack **b, int t)
{
	int	min;
	int	i;

	get_min_and_pos(a, &min, &i);
	if (i <= len_stack(*a) / 2)
	{
		while ((*a)->nb != min)
		{
			if (t)
				rotate(a);
			else
				rx(a, b, A);
		}
	}
	else
	{
		while ((*a)->nb != min)
		{
			if (t)
				r_rotate(a);
			else
				rrx(a, b, A);
		}
	}
}
