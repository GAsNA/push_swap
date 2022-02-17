/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_infinity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:46:48 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/11 15:24:16 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_max(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		max;

	max = (*a)->nb;
	tmp = (*a)->next;
	while (tmp)
	{
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	while ((*a)->nb != max)
		rx(a, b, A);
	px(a, b, B);
	return (max);
}

static void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;

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

void	sorting_infinity(t_stack **a, t_stack **b)
{
	// push dans b plus grand et plus petit
	// tans que size a != 0
		// tant que first a !< que last b et !> que first b, rr
		// pb
	// tant que plus grand pas en haut, rb (calculer si rb ou rrb mieux...??)
	// tout pa
	int	max;

	max = push_max(a, b); // calculer si rx ou rrx est mieux
	push_min(a, b); // calculer si rx ou rrx est mieux
	while (len_stack(*a) > 0)
	{
//		aff_stack(*a);
//		aff_stack(*b);
		while (((*a)->nb > ft_list_last((*b))->nb || (*a)->nb < (*b)->nb))
			rx(a, b, R);
		px(a, b, B);
	}
	while ((*b)->nb != max)
		rx(a, b, B); // calculer si rx ou rrx est mieux
	while (len_stack(*b) > 0)
		px(a, b, A);
}
