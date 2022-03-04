/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:07:00 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/04 05:31:55 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	conditions(int len, t_stack **a, t_stack **b)
{
	if (len > 1 && !is_sort(a))
	{
		if (len <= 3)
			sorting_three(a, b);
		else if (len <= 5)
			sorting_five(a, b);
		else
			sorting_infinity(a, b);
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	**args_char;
	t_stack	*a;
	t_stack	*b;

	args_char = get_args(av);
	if (ac == 1)
		return (0);
	if (!are_valid_args(args_char))
		error();
	else
	{
		a = tab_char_to_list(args_char);
		b = 0;
		len = len_stack(a);
		conditions(len, &a, &b);
		free_stack(a);
	}
	free_d_tab(args_char);
	return (0);
}
