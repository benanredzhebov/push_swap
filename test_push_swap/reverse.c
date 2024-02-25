/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:08:58 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/20 16:56:27 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_node **a, t_node **b, char c)
{
	t_node	*tmp;
	t_node	*tmp1;
	t_node	*tmp2;

	tmp = *a; //Assign the address pointed by a to tmp.
	tmp1 = tmp; // Assign the value of tmp to tmp1.
	while (tmp1->next->next) // Traverse the linked list until the second last node.
		tmp1 = tmp1->next; // Move to the next node.
	tmp2 = tmp1->next; // Assign the last node to tmp2
	tmp2->next = tmp; // Point the next of tmp2 (last node) to the first node.
	tmp1->next = NULL; // Set the next of the second last node to NULL
	*a = tmp2; // Set the start of the list to the last node(which is now first node)
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	if (c == 'R')
	{
		reverse(b, a, 'c');
		write(1, "rrr\n", 4);
	}
}

void print_list(t_node *node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	t_node *a = malloc(sizeof(t_node));
	t_node *b = malloc(sizeof(t_node));
	a->data = 1;
	a->next = malloc(sizeof(t_node));
	a->next->data = 2;
	a->next->next = malloc(sizeof(t_node));
	a->next->next->data = 3;
	a->next->next->next = NULL;

	printf("Before reverse:\n");
	print_list(a);

	reverse(&a, &b, 'a');

	printf("After reverse:\n");
	print_list(a);

	// Free memory
	free(a->next->next);
	free(a->next);
	free(a);
	free(b);

	return 0;
}