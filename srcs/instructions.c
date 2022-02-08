/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:04:08 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/08 12:43:12 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack **a, t_stack **b, int move)
{
	if (move == A)
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (move == B)
	{
		swap(b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (move == R)
	{
		swap(a);
		swap(b);
		ft_putstr_fd("ss\n", 1);
	}
}

void	px(t_stack **a, t_stack **b, int move)
{
	if (move == A)
	{
		push(a, b);
		ft_putstr_fd("pa\n", 1);
	}
	else if (move == B)
	{
		push(b, a);
		ft_putstr_fd("pb\n", 1);
	}
}

void	rx(t_stack **a, t_stack **b, int move)
{
	if (move == A)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (move == B)
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (move == R)
	{
		rotate(a);
		rotate(b);
		ft_putstr_fd("rr\n", 1);
	}
}

void	rrx(t_stack **a, t_stack **b, int move)
{
	if (move == A)
	{
		r_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (move == B)
	{
		r_rotate(b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (move == R)
	{
		r_rotate(a);
		r_rotate(b);
		ft_putstr_fd("rrr\n", 1);
	}
}
