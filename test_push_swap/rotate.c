/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:19:45 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/21 12:00:42 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function definition for rotating elements within a linked list
void rotate(t_node **a, t_node **b, char c) {
	t_node *tmp;
	t_node *tmp1;
	t_node *tmp2;

	if (a != NULL) {
		tmp = *a; // tmp is set to point to the first node of a
		tmp1 = tmp->next; // tmp1 is set to point to the second node of a
		tmp2 = tmp; // also set to point to the first node of a
		while (tmp2->next) // This loop makes tmp2 point to the last node of a 
			tmp2 = tmp2->next;
		tmp2->next = tmp; // The next pointer of the last node is set to the first node.
		tmp->next = NULL; // Next pointer of the first node is set to NULL. This effectively moves the first node to the end of the list
		*a = tmp1; // The head of a is updated to point to its first node(which was originally second node).
		if (c == 'a')
			write(1, "ra\n", 3);
	}
	if (b != NULL) {
		tmp = *b;
		tmp1 = tmp->next;
		tmp2 = tmp;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
		*b = tmp1;
		if (c == 'b')
			write(1, "rb\n", 3);
	}
	if (c == 'r') {
		rotate(a, NULL, 'c');
		rotate(NULL, b, 'c');
		write(1, "rr\n", 3);
	}
}

int main() {
	// Creating a linked list with 5 nodes
	t_node *head_a = malloc(sizeof(t_node));
	head_a->data = 10;

	t_node *second_a = malloc(sizeof(t_node));
	second_a->data = 20;
	head_a->next = second_a;

	t_node *third_a = malloc(sizeof(t_node));
	third_a->data = 30;
	second_a->next = third_a;

	third_a->next = NULL;

	// Creating a linked list with 3 nodes
	t_node *head_b = malloc(sizeof(t_node));
	head_b->data = 100;

	t_node *second_b = malloc(sizeof(t_node));
	second_b->data = 200;
	head_b->next = second_b;

	second_b->next = NULL;

	// Display the initial state of both lists
	printf("Initial state of list A: ");
	t_node *current_a = head_a;
	while (current_a != NULL) {
		printf("%d ", current_a->data);
		current_a = current_a->next;
	}
	printf("\n");

	printf("Initial state of list B: ");
	t_node *current_b = head_b;
	while (current_b != NULL) {
		printf("%d ", current_b->data);
		current_b = current_b->next;
	}
	printf("\n");

	// Rotate list A
	rotate(&head_a, NULL, 'a');
	printf("After rotating list A: ");
	current_a = head_a;
	while (current_a != NULL) {
		printf("%d ", current_a->data);
		current_a = current_a->next;
	}
	printf("\n");

	// Rotate list B
	rotate(NULL, &head_b, 'b');
	printf("After rotating list B: ");
	current_b = head_b;
	while (current_b != NULL) {
		printf("%d ", current_b->data);
		current_b = current_b->next;
	}
	printf("\n");

	// Rotate both lists
	rotate(&head_a, &head_b, 'r');
	printf("After rotating both lists: \n");
	printf("List A: ");
	current_a = head_a;
	while (current_a != NULL) {
		printf("%d ", current_a->data);
		current_a = current_a->next;
	}
	printf("\n");
	printf("List B: ");
	current_b = head_b;
	while (current_b != NULL) {
		printf("%d ", current_b->data);
		current_b = current_b->next;
	}
	printf("\n");

	// Freeing memory allocated for the linked list nodes
	t_node *temp;
	while (head_a != NULL) {
		temp = head_a;
		head_a = head_a->next;
		free(temp);
	}
	while (head_b != NULL) {
		temp = head_b;
		head_b = head_b->next;
		free(temp);
	}

	return 0;
}
