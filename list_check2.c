/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:42:11 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:42:11 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mid(t_node *head)
{
	return (size(head) / 2);
}

int	isreverse(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	issorted(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_min(t_node *head, int min)
{
	if (head->data == min)
		return (1);
	return (0);
}

int	check_max(t_node *head, int max)
{
	if (head->data == max)
		return (1);
	return (0);
}
