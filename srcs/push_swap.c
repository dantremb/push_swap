/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:44:48 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/06 12:44:38 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (ft_max(argv) || ft_digit(argv) || ft_doubles(argv))
		ft_send_error();
	else if (ft_check_sorted(argv) == 0 || argc <= 2)
		return (1);
	else
	{
		ft_init_all_stack(&stack, argv + 1, argc);
		ft_sort(&stack, argc);
		free (stack.a);
		free (stack.b);
	}
	if (stack.split_flag == 1)
		ft_free_array(argv);
}
