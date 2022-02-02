/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:07:00 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/02 15:28:45 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static char	**get_args(int ac, char **av)
{
	int		i;
	char	**ret;

	ret = malloc(ac * sizeof(char *));
	if (!ret)
		exit(0);
	i = 0;
	while (av[++i])
		ret[i - 1] = ft_strdup(av[i]);
	ret[i - 1] = 0;
	return (ret);
}

static int	*tab_char_to_int(int ac, char **av)
{
	int	i;
	int	*tab;

	tab = malloc((ac - 1) * sizeof(int));
	if (!tab)
		exit(0);
	i = -1;
	while (av[++i])
		tab[i] = ft_atoi(av[i]);
	return (tab);
}

int	main(int ac, char **av)
{
	char	**args_char;
	int		*args;
	int		len;

	args_char = get_args(ac, av);
	if (ac == 1 || !are_valid_args(args_char))
		error();
	else
	{
		len = ac - 1;
		args = tab_char_to_int(args_char);
		ft_putstr_fd("Hello !\n", 1);
	}
	free_d_tab(args_char);
	return (0);
}
