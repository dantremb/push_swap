/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:08:04 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/12 10:34:25 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_sort(t_stack *stack, int total_number)
{
	if (total_number < 4)
		ft_swap(stack, STACKA);
	else if (total_number < 5)
		ft_sort_three(stack);
	else if (total_number < 7)
		ft_sort_five(stack, total_number);
	else
	{
		ft_sort_big_a_to_b(stack, total_number);
		ft_sort_big_b_to_a(stack);
	}
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		ft_rotate(stack, STACKA);
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] > stack->a[2])
		ft_reverse_rotate(stack, STACKA);
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
		ft_swap(stack, STACKA);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
		ft_reverse_rotate(stack, STACKA);
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		ft_rotate(stack, STACKA);
}

void	ft_sort_five(t_stack *stack, int total_number)
{
	int	size;

	size = total_number - 3;
	while (stack->a[3] != 0)
	{
		if (stack->a[0] < size)
			ft_push(stack, STACKB);
		else
		{
			if (stack->a[ft_stack_size(stack->a) - 1] < size)
				ft_reverse_rotate(stack, STACKA);
			else
				ft_rotate(stack, STACKA);
		}
	}
	ft_sort_three(stack);
	if (stack->b[0] < stack->b[1])
		ft_swap(stack, STACKB);
	ft_push(stack, STACKA);
	if (stack->b[0] != 0)
		ft_push(stack, STACKA);
}

void	ft_sort_big_a_to_b(t_stack *stack, int total_number)
{
	while (stack->a[0] != 0)
	{
		stack->next = ft_find_next_smaller
			(stack->a, stack->chunk, total_number);
		stack->index = ft_return_index(stack->a, stack->next);
		while (stack->a[0] != stack->next)
		{
			if (stack->index < ft_stack_size(stack->a) / 2)
				ft_rotate(stack, STACKA);
			else
				ft_reverse_rotate(stack, STACKA);
		}
		ft_push(stack, STACKB);
		if (stack->b[0] < total_number / 2 && ft_stack_size(stack->b) != 1)
			ft_rotate(stack, STACKB);
		if (ft_number_remain(stack->a, stack->chunk, total_number) == 1)
			stack->chunk += stack->addchunk;
	}
	stack->beforelast = 0;
	stack->next = total_number - 1;
}

void	ft_sort_big_b_to_a(t_stack *stack)
{
	while (stack->b[0] != 0)
	{
		stack->index = ft_return_index(stack->b, stack->next);
		while (stack->b[0] != stack->next)
		{
			if (stack->b[0] == stack->next - 1)
			{
				ft_push(stack, STACKA);
				stack->beforelast = 1;
			}
			else if (stack->index < ft_stack_size(stack->b) / 2)
				ft_rotate(stack, STACKB);
			else
				ft_reverse_rotate(stack, STACKB);
		}
		ft_push(stack, STACKA);
		if (stack->beforelast == 1)
		{
			stack->next -= 2;
			stack->beforelast = 0;
			ft_swap(stack, STACKA);
		}
		else
			stack->next--;
	}
}
