/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:56:01 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/12 10:33:35 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack, int set)
{
	int	temp;

	if (set == STACKA || set == BOTHSTACK)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	if (set == STACKB || set == BOTHSTACK)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
	if (set == STACKA)
		ft_putstr("sa\n");
	if (set == STACKB)
		ft_putstr("sb\n");
	if (set == BOTHSTACK)
		ft_putstr("ss\n");
}

void	ft_rotate(t_stack *stack, int set)
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
	if (set == STACKA)
		ft_putstr("ra\n");
	if (set == STACKB)
		ft_putstr("rb\n");
	if (set == BOTHSTACK)
		ft_putstr("rr\n");
}

void	ft_reverse(int *stack)
{
	int	temp;
	int	i;

	i = 0;
	while (stack[i + 1])
		i++;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

void	ft_reverse_rotate(t_stack *stack, int set)
{
	if (set == STACKA || set == BOTHSTACK)
		ft_reverse(stack->a);
	if (set == STACKB || set == BOTHSTACK)
		ft_reverse(stack->b);
	if (set == STACKA)
		ft_putstr("rra\n");
	if (set == STACKB)
		ft_putstr("rrb\n");
	if (set == BOTHSTACK)
		ft_putstr("rrr\n");
}
