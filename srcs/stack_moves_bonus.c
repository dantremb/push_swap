/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:56:01 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/12 10:36:27 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_bonus(t_stack *stack, int set)
{
	int	temp;

	if (stack->a[1] != 0 && (set == STACKA || set == BOTHSTACK))
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	if (stack->b[1] != 0 && (set == STACKB || set == BOTHSTACK))
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
}

void	ft_rotate_bonus(t_stack *stack, int set)
{
	int	i;
	int	temp;

	i = -1;
	if (set == STACKA || set == BOTHSTACK)
	{
		temp = stack->a[0];
		while (stack->a[++i + 1])
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = temp;
	}
	if (set == STACKB || set == BOTHSTACK)
	{
		i = -1;
		temp = stack->b[0];
		while (stack->b[++i + 1])
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = temp;
	}
}

void	ft_reverse_rotate_bonus(t_stack *stack, int set)
{
	if (set == STACKA || set == BOTHSTACK)
		ft_reverse(stack->a);
	if (set == STACKB || set == BOTHSTACK)
		ft_reverse(stack->b);
}

void	ft_push_bonus(t_stack *stack, int set)
{
	if (set == STACKA && stack->b[0] != 0)
	{
		ft_add(stack->a, stack->b[0]);
		ft_remove(stack->b);
	}
	if (set == STACKB && stack->a[0] != 0)
	{
		ft_add(stack->b, stack->a[0]);
		ft_remove(stack->a);
	}
}
