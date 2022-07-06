/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:46:42 by dantremb          #+#    #+#             */
/*   Updated: 2022/07/06 12:39:01 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/includes/libft.h"

# define STACKA 2
# define STACKB 3
# define BOTHSTACK 4

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	chunk;
	int	addchunk;
	int	next;
	int	index;
	int	beforelast;
	int	split_flag;
}				t_stack;

void	ft_send_error(void);
int		ft_find_index(char *number, char **argv);
int		*ft_init_stack_a(char **argv, int total_number);
void	*ft_init_all_stack(t_stack *stack, char **argv, int total_number);

int		ft_digit(char **argv);
int		ft_check_sorted(char **argv);
int		ft_doubles(char **argv);
int		ft_max(char **argv);

void	ft_push(t_stack *stack, int set);
void	ft_swap(t_stack *stack, int set);
void	ft_rotate(t_stack *stack, int set);
void	ft_reverse_rotate(t_stack *stack, int set);
void	ft_add(int *stack, int number);
void	ft_remove(int *stack);
void	ft_reverse(int *stack);

void	ft_sort(t_stack *stack, int total_number);
void	ft_sort_three(t_stack *stack);
void	ft_sort_five(t_stack *stack);
void	ft_sort_big_a_to_b(t_stack *stack, int total_number);
void	ft_sort_big_b_to_a(t_stack *stack);

int		ft_stack_size(int *stack);
int		ft_return_index(int *stack, int number);
int		ft_number_remain(int *stack, int number, int side);
int		ft_find_next_smaller(int *stack, int chunk, int total_number);
void	ft_print_stack(t_stack *stack);

#endif
