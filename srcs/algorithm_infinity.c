/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_infinity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:46:48 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/01 14:01:50 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		fin_mov[2];
	int		mov[2];
	int		i;
	int		j;

	while (len_stack(*b) > 0)
	{
		tmp_b = (*b);
		fin_mov[0] = len_stack(*a) + 1;
		i = 0;
		while (tmp_b)
		{
			mov[0] = len_stack(*a) + 1;
			tmp_a = (*a);
			if (tmp_b->nb < tmp_a->nb && tmp_b->nb > get_last_stack(*a))
			{
				mov[0] = 0;
				mov[1] = i;
			}
			else
			{
				j = 1;
				while (tmp_a->next)
				{
					if (tmp_b->nb > tmp_a->nb && tmp_b->nb < tmp_a->next->nb)
					{
						mov[0] = j;
						mov[1] = i;
					}
					j++;
					tmp_a = tmp_a->next;
				}
				if (mov[0] == len_stack(*a) + 1)
				{
					mov[0] = get_pos_max(*a) + 1;
					mov[1] = i;
				}
			}
			if (fin_mov[0] == len_stack(*a) + 1)
			{
				fin_mov[0] = mov[0];
				fin_mov[1] = mov[1];
			}
			get_best_mov(fin_mov, mov, *a, *b);
			tmp_b = tmp_b->next;
			i++;
		}
		make_mov(fin_mov, a, b);
	}
}

void	sorting_infinity(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		lis_length;
	int		*lis;

	tmp = ft_stackdup(*a);
	rotate_to_min(&tmp, NULL, 1);
	lis = find_lis(&tmp, &lis_length);
	push_none_lis_to_b(a, b, lis_length, lis);
	sort(a, b);
	rotate_to_min(a, b, 0);
	free(lis);
	free_stack(tmp);
}
