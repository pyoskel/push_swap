/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:15:31 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/09 23:08:07 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "libft.h"

// // Temporary helper function to view the finished stack
// void	print_stack(t_node *stack, char stack_name)
// {
// 	printf("Stack %c: ", stack_name);
// 	while (stack)
// 	{
// 		printf("[%d, idx:%d] -> ", stack->value, stack->index);
// 		stack = stack->next;
// 	}
// 	printf("NULL\n");
// }

static int	init_stack(t_node **stack_a, char **args)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while (args[i])
	{
		new_node = stack_new_node(ft_atoi(args[i]));
		if (!new_node)
			return (0);
		stack_add_back(stack_a, new_node);
		i++;
	}
	return (1);
}

static int	free_and_error(t_node **stack_a, char **args, int argc)
{
	if (argc == 2 && args)
		free_args(args);
	if (stack_a && *stack_a)
		free_stack(stack_a);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_4_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_FAILURE);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (!args || !is_input_valid(args) || !init_stack(&stack_a, args))
		return (free_and_error(&stack_a, args, argc));
	if (argc == 2)
		free_args(args);
	if (!is_sorted(stack_a))
	{
		index_stack(&stack_a);
		sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// === TEST-CODE-1 ===
// int	main(int argc, char **argv)
// {
// 	char	**args;
// 	// 1. If no arguments or an empty string were passed
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (EXIT_FAILURE);
// 	if (argc == 2)
// 	{
// 		args = ft_split(argv[1], ' ');
// 		// ERROR-HANDLING: If ft_split fails (Malloc fail)
// 		if (!args)
// 			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		// If the arguments were passed individually (e.g., ./push_swap 3 2 5)
// 		// We skip argv[0] ("./push_swap")
//		// and point directly to the numbers
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
// 	printf("--- TEST END ---\n");
// 	// ============================
// 	// make
// 	// ./push_swap "42 1337 -5 0"
// 	// ./push_swap 42 1337 -5 0
// 	// ============================
// 	return (0);

// =============================================================================

// === TEST-CODE-2 ===
// For the validation.c function
	// printf("The input is valid!\n");
// ============================
// make
// ./push_swap 1 2 2 (Duplicate)
// ./push_swap 1 2 3000000000 (Integer overflow)
// ./push_swap 000000000000000000042 (is_length_valid)
// ./push_swap 1 2 abc (no digit)

// =============================================================================

// // === TEST-CODE-3 ===
// For the stack_utils.c function
// printf("\n--- Result ---\n");
// print_stack(stack_a);
// // ==================

// =============================================================================

// === TEST-CODE-4 ===
// For the swap.c function
// sa(&stack_a);
// printf("\n--- Result ---\n");
// print_stack(stack_a);
// ==================

// =============================================================================

// // === TEST-CODE-5 ===
// // For the push.c function
// 	printf("\n--- BEFORE ---\n");
// 	print_stack(stack_a, 'A');
// 	print_stack(stack_b, 'B');

// 	printf("\n--- ACTIONS ---\n");
// 	pb(&stack_a, &stack_b); // Pushes the 1st element from A to B
// 	pb(&stack_a, &stack_b); // Pushes the NEW 1st element from A to B
// 	sa(&stack_a);
// // Swaps the first two elements currently remaining on stack A

// 	printf("\n--- AFTER ---\n");
// 	print_stack(stack_a, 'A');
// 	print_stack(stack_b, 'B');
// 	// =====================================

// =============================================================================

// // === TEST-CODE-6 ===
// // For the rotate.c & rev_rotate.c function
	// printf("\n--- AFTER ---\n");
	// print_stack(stack_a, 'A');

	// printf("\n--- ACTIONS ---\n");
	// ra(&stack_a);
	// print_stack(stack_a, 'A');
// // The first number should now be at the very bottom!

	// rra(&stack_a); 
	// print_stack(stack_a, 'A');
// // We reverse rotate it. It should look exactly like the beginning again!
// 	// =====================================

// =============================================================================

// // === FINAL-TEST-CODE ===
// 	if (!is_sorted(stack_a))
// 	{
// 		index_stack(&stack_a);

// 		printf("\n=== START STATE (After indexing) ===\n");
// 		print_stack(stack_a, 'A');

// 		sort_stacks(&stack_a, &stack_b);

// 		printf("\n=== FINAL RESULT ===\n");
// 		print_stack(stack_a, 'A');
// 	}
// 	// ===============================