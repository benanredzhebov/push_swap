/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:20:06 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/18 14:21:00 by beredzhe         ###   ########.fr       */
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

// Function to swap two nodes in a linked list
void swap(t_node **a, t_node **b, char c) {
	t_node *tmp = *a;
	t_node *tmp1 = tmp->next;
	tmp->next = tmp1->next;
	tmp1->next = tmp;
	*a = tmp1;

	// Writing to stdout based on the character 'c'
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	if (c == 's') {
		swap(b, a, 'c');
		write(1, "ss\n", 3);
	}
}

int main() {
	// Creating a sample linked list
	t_node *head = NULL;
	t_node *second = NULL;
	t_node *third = NULL;

	head = (t_node *)malloc(sizeof(t_node));
	second = (t_node *)malloc(sizeof(t_node));
	third = (t_node *)malloc(sizeof(t_node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	// Swapping the first two nodes in the linked list
	swap(&head, &(head->next), 'a');

	// Displaying the updated linked list after swap
	t_node *tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");

	// Freeing allocated memory
	free(head);
	free(second);
	free(third);

	return 0;
}