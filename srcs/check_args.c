/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:11:58 by rleseur           #+#    #+#             */
/*   Updated: 2022/02/28 08:52:14 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_numbers(char *num)
{
	int	i;

	i = -1;
	while (num[++i])
		if (ft_isdigit(num[i]))
			return (1);
	return (0);
}

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
			if (!ft_isdigit(nums[i][j]) && nums[i][j] != '-'
				&& nums[i][j] != ' ' && nums[i][j] != '+')
				return (0);
			if (j > 0 && nums[i][j] == '-')
				return (0);
		}
		if (!has_numbers(nums[i]))
			return (0);
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
			if (ft_strncmp(nums[i], nums[j],
					ft_strlen(nums[i]) + ft_strlen(nums[j])) == 0)
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
