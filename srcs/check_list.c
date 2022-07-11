/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:45:48 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/11 14:45:50 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_digit(char **argv)
{
	int	ip;
	int	is;

	ip = 0;
	is = 0;
	while (argv[++ip])
	{
		is = -1;
		while (argv[ip][++is])
		{
			if (argv[ip][is] == '-')
				is++;
			if (!ft_isdigit(argv[ip][is]))
				return (1);
		}
	}
	return (0);
}

int	ft_max(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (ft_atoli(argv[i]) > 2147483647 || ft_atoli(argv[i]) < -2147483648)
			return (1);
	return (0);
}

int	ft_check_sorted(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i] && argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (1);
	}
	return (0);
}

int	ft_doubles(char **argv)
{
	int	ip;
	int	is;

	ip = 0;
	while (argv[++ip] && argv[ip + 1])
	{
		is = 0;
		while (argv[ip + ++is])
			if (ft_atoi(argv[ip]) == ft_atoi(argv[ip + is]))
				return (1);
	}
	return (0);
}
