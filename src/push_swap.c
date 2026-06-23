/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:15:31 by pabartoc          #+#    #+#             */
/*   Updated: 2026/06/23 01:34:33 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // temporarily

// Temporäre Hilfsfunktion, um den fertigen Stack zu sehen
void	print_stack(t_node *stack, char stack_name)
{
	printf("Stack %c: ", stack_name);
	while (stack)
	{
		printf("[%d, idx:%d] -> ", stack->value, stack->index);
		stack = stack->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	char	**args;
	t_node	*new_node;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	}
	else
		args = argv + 1;
	if (!is_input_valid(args))
	{
		if (argc == 2)
			free_args(args);
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	}
	i = 0;
	while (args[i])
	{
		new_node = stack_new_node(ft_atoi(args[i]));
		if (!new_node)
		{
			free_stack(&stack_a);
			if (argc == 2)
				free_args(args);
			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
		}
		stack_add_back(&stack_a, new_node);
		i++;
	}
	if (argc == 2)
		free_args(args);
	index_stack(&stack_a);
	// === UNSER GROSSER OPERATION-TEST ===
	printf("\n--- VORHER ---\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	printf("\n--- AKTIONEN ---\n");
	// Lass uns ein bisschen mit den Zeigern spielen!
	pb(&stack_a, &stack_b); // Schiebt das 1. Element von A nach B
	pb(&stack_a, &stack_b); // Schiebt das NEUE 1. Element von A nach B
	sa(&stack_a);           // Tauscht die ersten beiden Elemente, die jetzt noch auf A liegen

	printf("\n--- NACHHER ---\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	// =====================================
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// === TEST-CODE-1 ===
// int	main(int argc, char **argv)
// {
// 	char	**args;
// 	// 1. Wenn keine Argumente oder ein leerer String übergeben wurden
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (EXIT_FAILURE);
// 	if (argc == 2)
// 	{
// 		args = ft_split(argv[1], ' ');
// 		// FEHLER-ABFANGEN: Wenn ft_split fehlschlägt (Malloc-Fail)
// 		if (!args)
// 			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		// Wenn die Argumente einzeln übergeben wurden (z.B. ./push_swap 3 2 5)
// 		// Wir überspringen argv[0] ("./push_swap")
//		// und zeigen direkt auf die Zahlen
// 		args = argv + 1;
// 	}
	// 	// === TEMP TEST-CODE ===
	// printf("--- TEST START ---\n");
	// int	i = 0;
	// while (args[i] != NULL)
	// {
	// 	printf("args[%d] = %s\n", i, args[i]);
	// 	i++;
	// }
// 	printf("--- TEST ENDE ---\n");
// 	// ============================
// 	// make
// 	// ./push_swap "42 1337 -5 0"
// 	// ./push_swap 42 1337 -5 0
// 	// ============================
// 	return (0);

// =============================================================================

// === TEST-CODE-2 ===
// For the validation.c function
	// printf("Die Eingabe ist fehlerfrei!\n");
// ============================
// make
// ./push_swap 1 2 2 (Duplikat)
// ./push_swap 1 2 3000000000 (Überlauf)
// ./push_swap 000000000000000000042 (is_length_valid)
// ./push_swap 1 2 abc (no digit)

// =============================================================================

// // === TEST-CODE-3 ===
// For the stack_utils.c function
// printf("\n--- Ergebniss ---\n");
// print_stack(stack_a);
// // ==================

// =============================================================================

// === TEST-CODE-4 ===
// For the swap.c function
// sa(&stack_a);
// printf("\n--- Ergebniss ---\n");
// print_stack(stack_a);
// ==================

// =============================================================================

// // === TEST-CODE-5 ===
// // For the push.c function
// 	printf("\n--- VORHER ---\n");
// 	print_stack(stack_a, 'A');
// 	print_stack(stack_b, 'B');

// 	printf("\n--- AKTIONEN ---\n");
// 	// Lass uns ein bisschen mit den Zeigern spielen!
// 	pb(&stack_a, &stack_b); // Schiebt das 1. Element von A nach B
// 	pb(&stack_a, &stack_b); // Schiebt das NEUE 1. Element von A nach B
// 	sa(&stack_a);           // Tauscht die ersten beiden Elemente, die jetzt noch auf A liegen

// 	printf("\n--- NACHHER ---\n");
// 	print_stack(stack_a, 'A');
// 	print_stack(stack_b, 'B');
// 	// =====================================

// =============================================================================
