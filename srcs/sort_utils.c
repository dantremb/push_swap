/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:39:39 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/29 17:54:20 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i);
}

int	ft_return_index(int *stack, int number)
{
	int	i;

	i = -1;
	while (stack[++i])
		if (stack[i] == number)
			return (i);
	return (0);
}

int	ft_number_remain(int *stack, int chunk, int total_number)
{
	int	i;

	i = -1;
	while (stack[++i])
		if (stack[i] > ((total_number / 2) - chunk)
			&& stack[i] < ((total_number / 2) + chunk))
			return (0);
	return (1);
}

int	ft_find_next_smaller(int *stack, int chunk, int total_number)
{
	int	first;
	int	last;
	int	i;
	int	j;

	i = 0;
	i = 0;
	while (stack[i] <= ((total_number / 2) - chunk)
		|| stack[i] >= ((total_number / 2) + chunk))
		i++;
	first = stack[i];
	j = ft_stack_size(stack) - 1;
	while (stack[j] <= ((total_number / 2) - chunk)
		|| stack[j] >= ((total_number / 2) + chunk))
		j--;
	last = stack[j];
	if (total_number - j < i)
		return (last);
	else
		return (first);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	printf("\033[0;32mSTACK A  \033[0;37m");
	while (stack->a[++i] != 0)
		printf("[\033[0;36m%03d\033[0;37m]", stack->a[i]);
	printf("\n");
	i = -1;
	printf("\033[0;33mSTACK B  \033[0;37m");
	while (stack->b[++i] != 0)
		printf("[\033[0;36m%03d\033[0;37m]", stack->b[i]);
	printf("\n");
}
