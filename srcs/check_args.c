/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:11:58 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/01 16:13:48 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	all_numbers(char **nums)
{
	int	i;
	int	j;

	i = -1;
	while (nums[++i])
	{
		j = -1;
		while (nums[i][++j])
		{
			if (!ft_isdigit(nums[i][j]) && nums[i][j] != '-')
				return (0);
		}
	}
	return (1);
}

static int	no_bigger_than_int(char **nums)
{
	int		i;

	i = -1;
	while (nums[++i])
	{
		if (ft_atoi(nums[i]) > 2147483647 || ft_atoi(nums[i]) < -2147483648)
			return (0);
	}
	return (1);
}

static int	no_duplicates(char **nums)
{
	int	i;
	int	j;

	i = -1;
	while (nums[++i])
	{
		j = i;
		while (nums[++j])
		{
			if (ft_strncmp(nums[i], nums[j], 100) == 0)
				return (0);
		}
	}
	return (1);
}

int	are_valid_args(char **args)
{
	if (!all_numbers(args) || !no_bigger_than_int(args) || !no_duplicates(args))
		return (0);
	return (1);
}
