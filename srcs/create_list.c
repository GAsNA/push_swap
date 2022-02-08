/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:05:26 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/07 15:05:39 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_elem_list(int nb)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		exit(0);
	elem->nb = nb;
	elem->next = 0;
	return (elem);
}

t_stack	*tab_char_to_list(char **av)
{
	int		i;
	t_stack	*begin;
	t_stack	*back;

	begin = create_elem_list(ft_atoi(av[0]));
	back = begin;
	i = 0;
	while (av[++i])
	{
		back->next = create_elem_list(ft_atoi(av[i]));
		back = back->next;
	}
	return (begin);
}
