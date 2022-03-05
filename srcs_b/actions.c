/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 02:50:50 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/05 05:21:14 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

#define SIZE 5

static void	d_swap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

static void	d_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

static void	d_r_rotate(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
}

static int	make_mov(t_stack **a, t_stack **b, char str[SIZE])
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(str, "ss\n") == 0)
		d_swap(a, b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(b, a);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		d_rotate(a, b);
	else if (ft_strcmp(str, "rra\n") == 0)
		r_rotate(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		r_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		d_r_rotate(a, b);
	else
		return (error());
	return (1);
}

void	actions(t_stack **a, t_stack **b)
{
	char	str[SIZE];
	int		n;

	ft_memset(str, 0, SIZE);
	while (1)
	{
		n = read(STDIN_FILENO, str, SIZE);
		if (n == 0)
			break ;
		if (!make_mov(a, b, str))
			return ;
	}
	if (is_sort(a) && len_stack(*b) == 0)
		ok();
	else
		ko();
}
