/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:41:47 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/30 14:34:15 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add(int *stack, int number)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	while (i != 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = number;
}

void	ft_remove(int *stack)
{
	int	i;

	i = -1;
	while (stack[++i])
		stack[i] = stack[i + 1];
	stack[i - 1] = 0;
}

void	ft_push(t_stack *stack, int set)
{
	if (set == STACKA && stack->b[0] != 0)
	{
		ft_add(stack->a, stack->b[0]);
		ft_remove(stack->b);
		ft_putstr("pa\n");
	}
	if (set == STACKB && stack->a[0] != 0)
	{
		ft_add(stack->b, stack->a[0]);
		ft_remove(stack->a);
		ft_putstr("pb\n");
	}
	ft_print_stack(stack);
}
