/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 23:23:12 by pabartoc          #+#    #+#             */
/*   Updated: 2026/06/25 01:45:47 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*get_highest_index_node(t_node *stack)
{
	t_node	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->index > highest->index)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

static int	get_distance(t_node **stack, int counter)
{
	t_node	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == counter)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	sort_3(t_node **stack_a)
{
	t_node	*highest;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	highest = get_highest_index_node(*stack_a);
	if (*stack_a == highest)
		ra(stack_a);
	else if ((*stack_a)->next == highest)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	sort_4_5(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	push_counter;

	push_counter = 0;
	size = get_stack_size(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index == push_counter)
		{
			pb(stack_a, stack_b);
			push_counter++;
			size--;
		}
		else if (get_distance(stack_a, push_counter) <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
