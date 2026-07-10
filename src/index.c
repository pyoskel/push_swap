/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 02:53:01 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/10 22:30:30 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Find the node with the absolute smallest number that still has an index of -1
static t_node	*get_unindexed_smallest(t_node *stack)
{
	t_node	*smallest_node;

	smallest_node = NULL;
	while (stack)
	{
		if (stack->index == -1)
		{
			if (smallest_node == NULL || stack->value < smallest_node->value)
				smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

// Assigns a final rank (index) to each node
void	index_stack(t_node **stack)
{
	t_node	*smallest_node;
	int		current_index;

	current_index = 0;
	if (!stack || !*stack)
		return ;
	smallest_node = get_unindexed_smallest(*stack);
	while (smallest_node != NULL)
	{
		smallest_node->index = current_index;
		current_index++;
		smallest_node = get_unindexed_smallest(*stack);
	}
}
