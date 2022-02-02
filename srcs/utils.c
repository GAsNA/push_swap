/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:09 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/02 15:28:18 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	len_tab_int(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*duplicate_tab_int(int *tab)
{
	int	i;
	int	*dup;

	dup = malloc(len_tab_int(tab) * sizeof(int));
	if (!dup)
		exit(0);
	i = -1;
	while (tab[++i])
		dup[i] = tab[i];
	return (dup);
}
