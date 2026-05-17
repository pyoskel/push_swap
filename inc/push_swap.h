/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:15:33 by pabartoc          #+#    #+#             */
/*   Updated: 2026/03/07 22:01:28 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- Standard Bibliotheken --- */
# include <stdlib.h> // for malloc and free
# include <unistd.h> // for write

/* --- Datenstrukturen --- */

// Das ist unser "Listen-Element" (Node) für die Linked List
typedef struct s_node
{
	int				value; // Die echte Zahl aus dem Input (z.B. -42, 100)
	int				index; // Der Rang für deinen Algorithmus (z.B. 0, 1, 2...)
	struct s_node	*next; // Der "Schnitzeljagd"-Zeiger auf das nächste Element
}					t_node;

#endif