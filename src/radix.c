/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:04:48 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/08 21:32:35 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_max_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = get_stack_size(*stack_a);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index) >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

// befor while (*stack_b)
// // =========================================================
// printf("\n--- Mitten in Bit %d ---\n", i);
// print_stack(*stack_a, 'A');
// print_stack(*stack_b, 'B');
// printf("--- Ende in Bit %d ---\n", i);
// // =========================================================

// after while (*stack_b)
// // =========================================================
// printf("\n=== Nach Durchlauf für Bit %d ===\n", i);
// print_stack(*stack_a, 'A');
// // =========================================================