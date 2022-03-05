/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:36:17 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/05 03:32:30 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

void	swap(t_stack	**list)
{
	t_stack	*tmp;

	if (len_stack(*list) <= 1)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	push(t_stack	**list_d, t_stack	**list_s)
{
	t_stack	*tmp;
	t_stack	*elem;

	if (len_stack(*list_s) == 0)
		return ;
	if (*list_d)
	{
		elem = create_elem_list((*list_s)->nb);
		if (!elem)
			return ;
		elem->next = *list_d;
		*list_d = elem;
	}
	else
	{
		*list_d = create_elem_list((*list_s)->nb);
		if (!*list_d)
			return ;
	}
	tmp = (*list_s)->next;
	free(*list_s);
	*list_s = tmp;
}

void	rotate(t_stack	**list)
{
	t_stack	*newlist;
	t_stack	*last;

	if (len_stack(*list) <= 1)
		return ;
	last = *list;
	*list = (*list)->next;
	last->next = 0;
	newlist = *list;
	while ((newlist->next))
		newlist = newlist->next;
	newlist->next = last;
}

void	r_rotate(t_stack	**list)
{
	t_stack	*newlist;

	if (len_stack(*list) <= 1)
		return ;
	newlist = *list;
	while (newlist->next->next)
		newlist = newlist->next;
	newlist->next->next = *list;
	*list = newlist->next;
	newlist->next = 0;
}
