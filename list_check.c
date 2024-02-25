/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:41:57 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:41:57 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size(t_node *head)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	min(t_node *head)
{
	int		min;
	t_node	*tmp;

	tmp = head;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	max(t_node *head)
{
	int		max;
	t_node	*tmp;

	tmp = head;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	p_min(t_node *head)
{
	int		n;
	int		min;
	int		min_position;
	t_node	*tmp;

	n = 0;
	tmp = head;
	min = tmp->data;
	min_position = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_position = n;
		}
		n++;
		tmp = tmp->next;
	}
	return (min_position);
}

int	p_max(t_node *head)
{
	int		n;
	int		max;
	int		max_position;
	t_node	*tmp;

	n = 0;
	tmp = head;
	max = tmp->data;
	max_position = 0;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			max_position = n;
		}
		n++;
		tmp = tmp->next;
	}
	return (max_position);
}
