/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_infinity2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:44:04 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/01 14:04:12 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_none_lis_to_b(t_stack **a, t_stack **b, int lis_length, int *lis)
{
	int	i;

	while (len_stack(*a) > lis_length)
	{
		i = -1;
		while (++i < lis_length)
		{
			if (lis[i] == (*a)->nb)
				break ;
		}
		if (i == lis_length)
			px(a, b, B);
		else
			rx(a, b, A);
	}
}

int	get_last_stack(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->nb);
}

int	get_pos_max(t_stack *s)
{
	int	i;
	int	pos;
	int	max;

	max = s->nb;
	s = s->next;
	pos = 0;
	i = 1;
	while (s)
	{
		if (max < s->nb)
		{
			max = s->nb;
			pos = i;
		}
		i++;
		s = s->next;
	}
	return (pos);
}

void	get_best_mov(int fin_mov[2], int mov[2], t_stack *a, t_stack *b)
{
	int	mov_mov;
	int	mov_fin_mov;

	mov_mov = mov[0];
	if (mov[0] > len_stack(a) / 2)
		mov_mov = len_stack(a) - mov[0];
	if (mov[1] > len_stack(b) / 2)
		mov_mov += len_stack(b) - mov[1];
	else
		mov_mov += mov[1];
	mov_fin_mov = fin_mov[0];
	if (fin_mov[0] > len_stack(a) / 2)
		mov_fin_mov = len_stack(a) - fin_mov[0];
	if (fin_mov[1] > len_stack(b) / 2)
		mov_fin_mov += len_stack(b) - fin_mov[1];
	else
		mov_fin_mov += fin_mov[1];
	if (mov_mov < mov_fin_mov)
	{
		fin_mov[0] = mov[0];
		fin_mov[1] = mov[1];
	}
}
