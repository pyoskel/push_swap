/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:40:24 by pabartoc          #+#    #+#             */
/*   Updated: 2026/06/20 21:29:35 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new_node(int nbr)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = nbr;
	new_node->index = -1;
	new_node->next = (NULL);
	return (new_node);
}

void	stack_add_back(t_node **stack, t_node *new_node)
{
	
}
