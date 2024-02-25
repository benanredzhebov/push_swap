/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:41:26 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:41:26 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate(t_node *a, t_node *b, t_node **new, t_node **new2)
{
	t_node	*tmp;

	tmp = a;
	while (tmp)
	{
		insert_end(tmp->data, new);
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp)
	{
		insert_end(tmp->data, new2);
		tmp = tmp->next;
	}
}

void	cost_div2(t_node **a, t_node **b, t_node **x, int *i)
{
	while ((n_pos(*x, *b) > mid(*b) && n_pos(*x, *b) != 0)
		&& (target(*x, *a) > mid(*a) && target(*x, *a) != 0))
	{
		reverse1(a, b, 'R');
		*i = *i + 1;
	}
	while ((n_pos(*x, *b) == 0 || n_pos(*x, *b) <= mid(*b))
		&& (target(*x, *a) > mid(*a) && target(*x, *a) != 0))
	{
		reverse1(a, b, 'a');
		*i = *i + 1;
	}
	while ((target(*x, *a) == 0 || target(*x, *a) <= mid(*a))
		&& (n_pos(*x, *b) > mid(*b) && n_pos(*x, *b) != 0))
	{
		reverse1(b, a, 'b');
		*i = *i + 1;
	}
}

void	cost_div1(t_node **a, t_node **b, t_node **x, int *i)
{
	while ((n_pos(*x, *b) <= mid(*b) && n_pos(*x, *b) != 0)
		&& (target(*x, *a) <= mid(*a) && target(*x, *a) != 0))
	{
		rotate1(a, b, 'r');
		*i = *i + 1;
	}
	while ((n_pos(*x, *b) == 0 || n_pos(*x, *b) > mid(*b))
		&& (target(*x, *a) <= mid(*a) && target(*x, *a) != 0))
	{
		rotate1(a, b, 'a');
		*i = *i + 1;
	}
	while ((target(*x, *a) == 0 || target(*x, *a) > mid(*a))
		&& (n_pos(*x, *b) <= mid(*b) && n_pos(*x, *b) != 0))
	{
		rotate1(b, a, 'b');
		*i = *i + 1;
	}
}
