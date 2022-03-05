/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:00:05 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/05 05:17:13 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

int	main(int ac, char **av)
{
	char	**args_char;
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	args_char = get_args(av);
	if (!are_valid_args(args_char))
		error();
	else
	{
		a = tab_char_to_list(args_char);
		b = 0;
		actions(&a, &b);
		free_stack(a);
	}
	free_d_tab(args_char);
	return (0);
}
