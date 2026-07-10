/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:15:33 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/10 22:29:21 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- Standard Libraries --- */
# include <stdlib.h> // for malloc and free
# include <unistd.h> // for write
# include <limits.h> // for INT_MAX and INT_MIN
// # include <stdio.h> // IMPORTANT: For printf during testing!

/* --- Data Structure --- */
// (Node) for the linked list
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// value = The actual number from the input (e.g., -42, 100)
// index = The rank for the algorithm (e.g., 0, 1, 2...)
// *next = Pointer to the next element

/* --- TESTER Prototype --- */
// void	print_stack(t_node *stack, char stack_name);

/* --- Function Prototypes --- */
// validation.c
int		is_input_valid(char **args);

// utils.c
void	free_args(char **args);

// stack_utils.c
t_node	*stack_new_node(int value);
t_node	*find_last(t_node *stack);
void	stack_add_back(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);
int		get_stack_size(t_node *stack);

// index.c
void	index_stack(t_node **stack);

// swap.c
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// push.c
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

// rotate.c
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// rev_rotate.c
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// radix.c
void	radix_sort(t_node **stack_a, t_node **stack_b);

// small_sort.c
void	sort_3(t_node **stack_a);
void	sort_4_5(t_node **stack_a, t_node **stack_b);

#endif