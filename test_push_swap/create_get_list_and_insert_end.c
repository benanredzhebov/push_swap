/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_get_list_and_insert_end.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:19:13 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/21 17:56:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(int x, t_node **head)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	new->data = x;
	new->cost = -5;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	get_list(char **str, t_node **head)
{
	int	i;

	i = 1;
	while (str[i])
	{
		insert_end(atoi(str[i]), head);
		i++;
	}
}

void print_list(t_node *head) {
	t_node *tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	char *array[] = {"./program", "123", "456", "789", NULL};
	t_node *head = NULL;

	get_list(array, &head);
	print_list(head);

	// Don't forget to free the memory
	t_node *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}

	return 0;
}
