/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:19:32 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/17 08:19:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function definition for checking if the linked list is sorted
int	issorted(t_node *head) {
	t_node *tmp = head;

	// Traverse the linked list and check for sorted order
	while (tmp->next != NULL) {
		if (tmp->data > tmp->next->data)
			return 0; // List is not sorted
		tmp = tmp->next;
	}
	return 1; // List is sorted
}


int main() {
	// Creating a sorted linked list with 5 nodes
	t_node *head = malloc(sizeof(t_node));
	head->data = 10;

	t_node *second = malloc(sizeof(t_node));
	second->data = 20;
	head->next = second;

	t_node *third = malloc(sizeof(t_node));
	third->data = 30;
	second->next = third;

	t_node *fourth = malloc(sizeof(t_node));
	fourth->data = 40;
	third->next = fourth;

	t_node *fifth = malloc(sizeof(t_node));
	fifth->data = 50;
	fourth->next = fifth;
	fifth->next = NULL;

	// Calling the issorted function to check if the linked list is sorted
	int sorted = issorted(head);
	if (sorted)
	printf("The linked list is sorted.\n");
	else
		printf("The linked list is not sorted.\n");

	// Freeing memory allocated for the linked list nodes
	t_node *current = head;
	while (current != NULL) {
		t_node *temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}
