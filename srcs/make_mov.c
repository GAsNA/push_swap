/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:57:31 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/01 14:03:52 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_mov_rx(int *fin_mov, t_stack **a, t_stack **b, int move)
{
	while (*fin_mov > 0)
	{
		rx(a, b, move);
		(*fin_mov)--;
	}
}

static void	make_mov_rrx(int *fin_mov, t_stack **a, t_stack **b, int move)
{
	int	len;

	len = len_stack(*b);
	if (move == A)
		len = len_stack(*a);
	while (*fin_mov < len)
	{
		rrx(a, b, move);
		(*fin_mov)++;
	}
}

static void	make_mov_rr(int fin_mov[2], t_stack **a, t_stack **b)
{
	while (fin_mov[0] != 0 && fin_mov[1] != 0)
	{
		rx(a, b, R);
		fin_mov[0]--;
		fin_mov[1]--;
	}
}

static void	make_mov_rrr(int fin_mov[2], t_stack **a, t_stack **b)
{
	while (fin_mov[0] < len_stack(*a) && fin_mov[1] < len_stack(*b))
	{
		rrx(a, b, R);
		fin_mov[0]++;
		fin_mov[1]++;
	}
}

void	make_mov(int fin_mov[2], t_stack **a, t_stack **b)
{
	if (fin_mov[0] <= len_stack(*a) / 2 && fin_mov[1] <= len_stack(*b) / 2)
	{
		make_mov_rr(fin_mov, a, b);
		make_mov_rx(&fin_mov[0], a, b, A);
		make_mov_rx(&fin_mov[1], a, b, B);
	}
	else if (fin_mov[0] > len_stack(*a) / 2 && fin_mov[1] > len_stack(*b) / 2)
	{
		make_mov_rrr(fin_mov, a, b);
		make_mov_rrx(&fin_mov[0], a, b, A);
		make_mov_rrx(&fin_mov[1], a, b, B);
	}
	else if (fin_mov[0] <= len_stack(*a) / 2 && fin_mov[1] > len_stack(*b) / 2)
	{
		make_mov_rx(&fin_mov[0], a, b, A);
		make_mov_rrx(&fin_mov[1], a, b, B);
	}
	else if (fin_mov[0] > len_stack(*a) / 2 && fin_mov[1] <= len_stack(*b) / 2)
	{
		make_mov_rrx(&fin_mov[0], a, b, A);
		make_mov_rx(&fin_mov[1], a, b, B);
	}
	px(a, b, A);
}
