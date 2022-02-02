/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:36:17 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/02 15:24:12 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(int *list)
{
	int	tmp;

	if (len_tab_int(list) <= 1)
		return ;
	tmp = list[0];
	list[0] = list[1];
	list[1] = tmp;
}

int	*push(int *list_d, int *list_s)
{
	int	i;
	int	*new_list;

	if (len_tab_int(list_s) == 0)
		return (0);
	new_list = malloc((len_tab_int(list_d) + 1) * sizeof(int));
	if (!new_list)
		exit(0);
	new_list[0] = list_s[0];
	i = -1;
	while (list_d[++i])
		new_list[i + 1] = list_d[i];
	free(list_d);
	list_d = duplicate_tab_int(new_list);
	free(new_list);
	return (list_d);
}

int	main()
{
	int	i;
	int	*tab_d;
	int	*tab_s;

	tab_d = malloc(3 * sizeof(int));
	tab_d[0] = 5;
	tab_d[1] = 4;
	tab_d[2] = 7;

	tab_s = malloc(sizeof(int));
	tab_s[0] = 9;

//	tab_d = push(tab_d, tab_s);
	i = 0;
	while (tab_d[i])
	{
		ft_putnbr_fd(tab_d[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	i = 0;
	while (tab_s[i])
	{
		ft_putnbr_fd(tab_s[i], 1);
		i++;
	}
	free(tab_d);
	free(tab_s);
}
