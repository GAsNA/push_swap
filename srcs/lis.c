/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:51:58 by rleseur           #+#    #+#             */
/*   Updated: 2022/03/01 10:25:23 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define INT_INF 10000

static int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

static int	*get_answer(int *lis_length, int *b, int *index, int size)
{
	int	*answer;
	int	tmp;
	int	i;

	answer = malloc((*lis_length + 1) * sizeof(int));
	if (!answer)
		return (0);
	i = size;
	tmp = *lis_length;
	while (--i >= 0)
	{
		if (index[i] == tmp)
		{
			answer[tmp] = b[i];
			--tmp;
		}
	}
	*lis_length += 1;
	free(b);
	free(index);
	return (answer);
}

static void	init(t_stack **a, int **b, int *lis_length, int **lis)
{	
	*b = stack_to_tab(a);
	*lis_length = -1;
	*lis = malloc(len_stack(*a) * sizeof(int));
	if (!*lis)
		return ;
	*lis[0] = *b[0];
}

int	*find_lis(t_stack **a, int *lis_length)
{
	int	i;
	int	size;
	int	*b;
	int	*lis;
	int	*index;

	init(a, &b, lis_length, &lis);
	size = len_stack(*a);
	i = 0;
	while (++i < size)
		lis[i] = INT_INF;
	index = malloc(len_stack(*a) * sizeof(int));
	if (!index)
		return (0);
	i = -1;
	while (++i < size)
	{
		index[i] = search_replace(lis, 0, i, b[i]);
		if (*lis_length < index[i])
			*lis_length = index[i];
	}
	free(lis);
	return (get_answer(lis_length, b, index, size));
}
