/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_infinity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:46:48 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/28 17:55:17 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_min_tmp(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		i;

	min = (*a)->nb;
	tmp = (*a)->next;
	while (tmp)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	tmp = (*a);
	i = -1;
	while (tmp->nb != min && ++i < len_stack(*a))
		tmp = tmp->next;
	if (i <= len_stack(*a) / 2)
	{
		while ((*a)->nb != min)
			rotate(a);
	}
	else
	{
		while ((*a)->nb != min)
			r_rotate(a);
	}
}

static void	rotate_to_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		i;

	min = (*a)->nb;
	tmp = (*a)->next;
	while (tmp)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	tmp = (*a);
	i = -1;
	while (tmp->nb != min && ++i < len_stack(*a))
		tmp = tmp->next;
	if (i <= len_stack(*a) / 2)
	{
		while ((*a)->nb != min)
			rx(a, b, A);
	}
	else
	{
		while ((*a)->nb != min)
			rrx(a, b, A);
	}
}

static void	push_none_lis_to_b(t_stack **a, t_stack **b, int lis_length, int *lis)
{
	int	i;

	while (len_stack(*a) > lis_length)
	{
		i = -1;
		while (++i < lis_length)
		{
			if (lis[i] == (*a)->nb)
				break;
		}
		if (i == lis_length)
			px(a, b, B);
		else
			rx(a, b, A);
	}
}

static int	get_last_stack(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->nb);
}

static int	get_pos_max(t_stack *s)
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

static void	get_best_mov(int fin_mov[2], int mov[2], t_stack *a, t_stack *b)
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

void	make_mov(int fin_mov[2], t_stack **a, t_stack **b)
{
	if (fin_mov[0] <= len_stack(*a) / 2 && fin_mov[1] <= len_stack(*b) / 2)
	{
		while (fin_mov[0] != 0 && fin_mov[1] != 0)
		{
			rx(a, b, R);
			fin_mov[0]--;
			fin_mov[1]--;
		}
		while (fin_mov[0] > 0)
		{
			rx(a, b, A);
			fin_mov[0]--;
		}
		while (fin_mov[1] > 0)
		{
			rx(a, b, B);
			fin_mov[1]--;
		}
	}
	else if (fin_mov[0] > len_stack(*a) / 2 && fin_mov[1] > len_stack(*b) / 2)
	{
		while (fin_mov[0] < len_stack(*a) && fin_mov[1] < len_stack(*b))
		{
			rrx(a, b, R);
			fin_mov[0]++;
			fin_mov[1]++;
		}
		while (fin_mov[0] < len_stack(*a))
		{
			rrx(a, b, A);
			fin_mov[0]++;
		}
		while (fin_mov[1] < len_stack(*b))
		{
			rrx(a, b, B);
			fin_mov[1]++;
		}
	}
	else if (fin_mov[0] <= len_stack(*a) / 2 && fin_mov[1] > len_stack(*b) / 2)
	{
		while (fin_mov[0] > 0)
		{
			rx(a, b, A);
			fin_mov[0]--;
		}
		while (fin_mov[1] < len_stack(*b))
		{
			rrx(a, b, B);
			fin_mov[1]++;
		}
	}
	else if (fin_mov[0] > len_stack(*a) / 2 && fin_mov[1] <= len_stack(*b) / 2)
	{
		while (fin_mov[0] < len_stack(*a))
		{
			rrx(a, b, A);
			fin_mov[0]++;
		}
		while (fin_mov[1] > 0)
		{
			rx(a, b, B);
			fin_mov[1]--;
		}
	}
	px(a, b, A);
}

void	sorting_infinity(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		i;
	int		j;
	int		lis_length;
	int		*lis;
	int		fin_mov[2];
	int		mov[2];

	tmp = ft_stackdup(*a);
	rotate_to_min_tmp(&tmp);
	lis = find_lis(&tmp, &lis_length);
	push_none_lis_to_b(a, b, lis_length, lis);
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
			//printf("MOV for %i: {%i, %i}\n", tmp_b->nb, mov[0], mov[1]);
			get_best_mov(fin_mov, mov, *a, *b);
			//printf("BEST MOV: {%i, %i}\n", fin_mov[0], fin_mov[1]);
			tmp_b = tmp_b->next;
			i++;
		}
		make_mov(fin_mov, a, b);
	}
	rotate_to_min(a, b);
}
