/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:41:01 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:41:01 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp->data);
}

int	n_pos(t_node *x, t_node *head)
{
	t_node	*tmp;
	int		n;

	n = 0;
	tmp = head;
	while (tmp && tmp->data != x->data)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

t_node	*max_n(t_node *head)
{
	int		max;
	t_node	*tmp;
	t_node	*tmp1;

	tmp = head;
	tmp1 = tmp;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			tmp1 = tmp;
		}
		tmp = tmp->next;
	}
	return (tmp1);
}

void	target_div(t_node *x, t_node *a, t_node *tmp, int *i)
{
	while (issorted(a) && tmp && x->data > tmp->data)
	{
		*i = *i + 1;
		tmp = tmp->next;
	}
	if (!issorted(a))
	{
		if (x->data < last(a))
		{
			tmp = max_n(a);
			tmp = tmp->next;
			*i = p_max(a) + 1;
		}
		while (tmp && x->data > tmp->data)
		{
			*i = *i + 1;
			tmp = tmp->next;
		}
	}
}

int	target(t_node *x, t_node *a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a;
	if (x->data < min(a) || x->data > max(a))
		i = p_min(a);
	else if (x->data > min(a) && x->data < max(a))
	{
		target_div(x, a, tmp, &i);
	}
	return (i);
}
