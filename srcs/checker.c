/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:38:59 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/30 14:44:10 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_execute_command(t_stack *stack)
{
	
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
