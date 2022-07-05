/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:38:59 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/05 14:39:29 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

int	ft_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack->a[++i])
		if(stack->a[i] < stack->a[i - 1])
			return (1);
	return (0);
}

void	ft_do_move(char *test, t_stack *stack)
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
		ft_send_error();
}

void	ft_execute_command(t_stack *stack)
{
	char	*test;

	while (1)
	{
		test = ft_get_next_line(0);
		if (!test)
			break ;
		ft_do_move(test, stack);
		free (test);
	}
	if (ft_sorted(stack) == 1)
		printf("KO\n");
	else
		printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	*split;
	int		split_flag;
	
	split_flag = 0;
	if (ft_strchr(argv[1], 32) != NULL && argc == 2)
	{
		split = ft_strjoin("push_swap ", argv[1]);
		argc = ft_split_size(split, 32);
		argv = ft_split(split, 32);
		free (split);
		split_flag = 1;
	}
	if (ft_check_min_max(argv) || ft_check_isdigit(argv) || ft_check_doubles(argv))
		ft_send_error();
	else if (ft_check_sorted(argv) == 0|| argc <= 2)
		return (1);
	else
	{
		ft_init_all_stack(&stack, argv + 1, argc);
		ft_execute_command(&stack);
		free (stack.a);
		free (stack.b);
	}
	if (split_flag == 1)
		ft_free_array(argv);
	return (0);
}
