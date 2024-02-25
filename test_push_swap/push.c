/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:49:04 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/22 11:33:15 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for write function

// Structure for a node in the linked list
typedef struct s_node {
	int data;
	struct s_node *next;
} t_node;

// Function to push a node from one linked list to another
void push(t_node **a, t_node **b, char c) {
	t_node *tmp = *a;
	t_node *tmp1 = tmp->next;
	tmp->next = *b;
	*b = tmp;
	*a = tmp1;

	// Writing to stdout based on the character 'c'
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

int main() {
	// Creating two sample linked lists
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	// Adding some elements to stack_a
	t_node *node1 = (t_node *)malloc(sizeof(t_node));
	node1->data = 10;
	node1->next = stack_a;
	stack_a = node1;

	t_node *node2 = (t_node *)malloc(sizeof(t_node));
	node2->data = 20;
	node2->next = stack_a;
	stack_a = node2;

	// Pushing a node from stack_a to stack_b
	push(&stack_a, &stack_b, 'b');

	// Displaying the updated states of stack_a and stack_b
	printf("After pushing:\n");

	printf("Stack A: ");
	t_node *tmp_a = stack_a;
	while (tmp_a) {
		printf("%d ", tmp_a->data);
		tmp_a = tmp_a->next;
	}
	printf("\n");

	printf("Stack B: ");
	t_node *tmp_b = stack_b;
	while (tmp_b) {
		printf("%d ", tmp_b->data);
		tmp_b = tmp_b->next;
	}
	printf("\n");

	// Freeing allocated memory
	free(node1);
	free(node2);

	return 0;
}
