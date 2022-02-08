/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:51:03 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/08 16:46:51 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_stack **a, t_stack **b)
{
	if ((*a)->nb > (*a)->next->nb)
	{
		if ((*a)->nb < (*a)->next->next->nb)
			sx(a, b, A);
		else if ((*a)->next->nb < (*a)->next->next->nb)
			rx(a, b, A);
		else
		{
			sx(a, b, A);
			rrx(a, b, A);
		}
	}
	else
	{
		if ((*a)->nb > (*a)->next->next->nb)
			rrx(a, b, A);
		else
		{
			sx(a, b, A);
			rx(a, b, A);
		}
	}
}
