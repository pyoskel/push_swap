/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 23:23:12 by pabartoc          #+#    #+#             */
/*   Updated: 2026/06/25 00:16:14 by pabartoc         ###   ########.fr       */
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
