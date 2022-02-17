/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:07:00 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/11 15:23:44 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		len;
	char	**args_char;
	t_stack	*a;
	t_stack	*b;

	args_char = get_args(av);
	if (ac == 1 || !are_valid_args(args_char))
		error();
	else
	{
		a = tab_char_to_list(args_char);
		b = 0;
		len = len_stack(a);
		if (len <= 3)
			sorting_three(&a, &b);
		else if (len <= 5)
			sorting_five(&a, &b);
		else
			sorting_infinity(&a, &b);
	//	aff_stack(a);
		//aff_stack(b);
		free_stack(a);
	}
	free_d_tab(args_char);
	return (0);
}
