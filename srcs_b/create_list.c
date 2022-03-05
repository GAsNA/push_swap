/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:05:26 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/05 04:45:10 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

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

	if (!av[0])
		return (0);
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
