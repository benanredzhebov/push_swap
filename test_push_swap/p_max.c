/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_max.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:19:36 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/17 08:19:37 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function definition for finding the position of the maximum value in the linked list
int p_max(t_node *head) {
	int n = 0;
	int max = head->data;
	int max_position = 0;
	t_node *tmp = head;

	// Traverse the linked list and find the position of the maximum value
	while (tmp != NULL) {
		if (tmp->data > max) {
			max = tmp->data;
			max_position = n;
		}
		n++;
		tmp = tmp->next;
	}
	return max_position;
}

int main() {
	// Creating a linked list with 5 nodes
	t_node *head = malloc(sizeof(t_node));
	head->data = 10;

	t_node *second = malloc(sizeof(t_node));
	second->data = 30;
	head->next = second;

	t_node *third = malloc(sizeof(t_node));
	third->data = 20;
	second->next = third;

	t_node *fourth = malloc(sizeof(t_node));
	fourth->data = 50;
	third->next = fourth;

	t_node *fifth = malloc(sizeof(t_node));
	fifth->data = 40;
	fourth->next = fifth;
	fifth->next = NULL;

	// Calling the p_max function to find the position of the maximum value
	int max_position = p_max(head);
	printf("Position of the maximum value: %d\n", max_position);

	// Freeing memory allocated for the linked list nodes
	t_node *current = head;
	while (current != NULL) {
		t_node *temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}
