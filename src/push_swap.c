/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:15:31 by pabartoc          #+#    #+#             */
/*   Updated: 2026/06/20 20:41:01 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // temporarily

int	main(int argc, char **argv)
{
	char	**args;
	t_node	*new_node;
	t_node	*stack_a;
	int		i;

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
		if (args == 2)
			free_args(args);
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	}
	i = 0;
	while (args[i])
	{
		new_node = stack_new_node(ft_atoi(args[i]));
		if (!new_node)
		{
			if (args == 2)
				free_args(args);
			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
		}
		stack_add_back(stack_a, new_node);
	}
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
	// printf("Die Eingabe ist fehlerfrei!\n");
// ============================
// Test for validation.c

// make
// ./push_swap 1 2 2 (Duplikat)
// ./push_swap 1 2 3000000000 (Überlauf)
// ./push_swap 1 2 abc (no digit)