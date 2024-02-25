/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:19:27 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/21 18:36:03 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int	data;
	struct s_node *next;
} t_node;

int	extra_case(t_node *head)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = head;
	tmp1 = tmp;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->data == tmp1->data)
			{
				write(1, "Error: there are duplicates\n", 28);
				return (1);
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int main() {
	t_node *head = NULL;

	// Insert some data into the list
	insert_end(1, &head);
	insert_end(2, &head);
	insert_end(3, &head);
	insert_end(2, &head);  // This will be a duplicate

	if (extra_case(head)) {
		printf("There are duplicate nodes.\n");
	} else {
		printf("There are no duplicate nodes.\n");
	}

	// Don't forget to free the memory
	t_node *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}

	return 0;
}
