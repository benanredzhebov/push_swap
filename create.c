/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:41:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:41:40 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_list(char **str, t_node **head)
{
	int	i;

	i = 1;
	while (str[i])
	{
		insert_end(ft_atoi(str[i]), head);
		i++;
	}
}

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

void	clear(t_node **head)
{
	t_node	*tmp;

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
