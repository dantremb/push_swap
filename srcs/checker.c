/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:38:59 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/06 23:54:28 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

int	ft_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->a[++i])
		if (stack->a[i] < stack->a[i - 1])
			return (1);
	return (0);
}

int	ft_do_move(char *test, t_stack *stack)
{
	if (ft_strncmp(test, "pa\n", 3) == 0)
		ft_push_bonus(stack, STACKA);
	else if (ft_strncmp(test, "pb\n", 3) == 0)
		ft_push_bonus(stack, STACKB);
	else if (ft_strncmp(test, "sa\n", 3) == 0)
		ft_swap_bonus(stack, STACKA);
	else if (ft_strncmp(test, "sb\n", 3) == 0)
		ft_swap_bonus(stack, STACKB);
	else if (ft_strncmp(test, "ss\n", 3) == 0)
		ft_swap_bonus(stack, BOTHSTACK);
	else if (ft_strncmp(test, "ra\n", 3) == 0)
		ft_rotate_bonus(stack, STACKA);
	else if (ft_strncmp(test, "rb\n", 3) == 0)
		ft_rotate_bonus(stack, STACKB);
	else if (ft_strncmp(test, "rra\n", 4) == 0)
		ft_reverse_rotate_bonus(stack, STACKA);
	else if (ft_strncmp(test, "rrb\n", 4) == 0)
		ft_reverse_rotate_bonus(stack, STACKB);
	else if (ft_strncmp(test, "rrr\n", 4) == 0)
		ft_reverse_rotate_bonus(stack, BOTHSTACK);
	else if (ft_strncmp(test, "rr\n", 3) == 0)
		ft_rotate_bonus(stack, BOTHSTACK);
	else
		return (1);
	return (0);
}

void	ft_execute_command(t_stack *stack, char **argv)
{
	char	*test;
	int		ret;

	ret = 0;
	while (1)
	{
		test = ft_get_next_line(0);
		if (!test)
			break ;
		ret = ft_do_move(test, stack);
		if (ret == 1)
		{
			if (stack->split_flag == 1)
				ft_free_array(argv);
			exit(1);
		}
		free (test);
	}
	if (ft_sorted(stack) == 1)
		printf("KO\n");
	else
		printf("OK\n");
}

void	ft_checker(int argc, char **argv, t_stack *stack)
{
	if (ft_digit(argv) || ft_doubles(argv) || ft_doubles(argv))
	{
		if (stack->split_flag == 1)
			ft_free_array(argv);
		ft_send_error();
	}
	else
	{
		ft_init_all_stack(stack, argv + 1, argc);
		ft_execute_command(stack, argv);
		free (stack->a);
		free (stack->b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	*split;

	stack.split_flag = 0;
	if (ft_strchr(argv[1], 32) != NULL && argc == 2)
	{
		split = ft_strjoin("push_swap ", argv[1]);
		argc = ft_split_size(split, 32);
		argv = ft_split(split, 32);
		free (split);
		stack.split_flag = 1;
	}
	ft_checker(argc, argv, &stack);
	if (stack.split_flag == 1)
		ft_free_array(argv);
	return (0);
}
