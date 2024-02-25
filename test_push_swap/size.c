/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:48:45 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/18 09:49:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct s_node {
	int data;
	struct s_node *next;
} t_node;

// Function to calculate the size of the linked list
int size(t_node *head) {
	t_node *tmp = head;
	int i = 0;
	while (tmp) {
		i++;
		tmp = tmp->next;
	}
	return i;
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

	// Calculate the size of the linked list
	int listSize = size(head);

	// Print the size of the linked list
	printf("Size of the linked list is: %d\n", listSize);

	// Freeing allocated memory
	free(head);
	free(second);
	free(third);

	return 0;
}