/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:19:51 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/17 08:19:52 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(t_node **head)
{
	t_node *tmp;

	if (head == NULL)
		return ;
	while (*head != NULL)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
		tmp = *head;
	}
}


int	main()
{
	//Creating a linked list
	t_node *head = malloc(sizeof(t_node));
	head->data = 1;

	t_node *second = malloc(sizeof(t_node));
	second->data = 2;
	head->next = second;

	t_node *third = malloc(sizeof(t_node));
	third->data = 3;
	second->next = third;
	third->next = NULL;

	//Displaying the initial linked list
	printf("Initial linked list: \n");
	t_node *current = head;
	while (current != NULL)
	{
		printf("%d ->", current ->data);
		current = current->next;
	}
	printf("NULL\n");

	// Clearing the linked list
	clear(&head);

	//Displaying the cleared linked list
	printf("\nLinked list after clearing: \n");
	current = head;
	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");

	return (0);
}