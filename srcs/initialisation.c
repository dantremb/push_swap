/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:39:36 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/12 09:59:46 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_send_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

int	ft_find_index(char *number, char **argv)
{
	int	i;
	int	index;

	index = 1;
	i = -1;
	while (argv[++i])
		if (ft_atoi(number) > ft_atoi(argv[i]))
			index++;
	return (index);
}

int	*ft_init_stack_a(char **argv, int total_number)
{
	int	*temp;
	int	i;

	temp = ft_calloc(sizeof(int), total_number);
	if (!temp)
		ft_send_error();
	i = -1;
	while (argv[++i] != NULL)
		temp[i] = ft_find_index(argv[i], argv);
	return (temp);
}

void	*ft_init_all_stack(t_stack *stack, char **argv, int total_number)
{
	stack->a = ft_init_stack_a(argv, total_number);
	stack->b = ft_calloc(sizeof(int), total_number);
	if (!stack->b)
	{
		free(stack->a);
		ft_send_error();
	}
	if (total_number > 250)
		stack->chunk = 30;
	else
		stack->chunk = 15;
	stack->addchunk = stack->chunk;
	return (stack);
}
