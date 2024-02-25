/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:42:42 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:42:42 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_node **a, t_node **b)
{
	if (size(*a) == 3 && (!issorted(*a)))
	{
		if (p_max(*a) == 0)
			rotate(a, b, 'a');
		if (p_min(*a) == 2)
			reverse(a, b, 'a');
		if (p_min(*a) == 0 && !issorted(*a))
			reverse(a, b, 'a');
		if (!issorted(*a))
			swap(a, b, 'a');
		sort3(a, b);
	}
}

void	costbenefit(t_node **a, t_node **b)
{
	t_node	*x;

	x = NULL;
	x = choose(b);
	while ((n_pos(x, *b) <= mid(*b) && n_pos(x, *b) != 0)
		&& (target(x, *a) <= mid(*a) && target(x, *a) != 0))
		rotate(a, b, 'r');
	while ((n_pos(x, *b) == 0 || n_pos(x, *b) > mid(*b))
		&& (target(x, *a) <= mid(*a) && target(x, *a) != 0))
		rotate(a, b, 'a');
	while ((target(x, *a) == 0 || target(x, *a) > mid(*a))
		&& (n_pos(x, *b) <= mid(*b) && n_pos(x, *b) != 0))
		rotate(b, a, 'b');
	while ((n_pos(x, *b) > mid(*b) && n_pos(x, *b) != 0)
		&& (target(x, *a) > mid(*a) && target(x, *a) != 0))
		reverse(a, b, 'R');
	while ((n_pos(x, *b) == 0 || n_pos(x, *b) <= mid(*b))
		&& (target(x, *a) > mid(*a) && target(x, *a) != 0))
		reverse(a, b, 'a');
	while ((target(x, *a) == 0 || target(x, *a) <= mid(*a))
		&& (n_pos(x, *b) > mid(*b) && n_pos(x, *b) != 0))
		reverse(b, a, 'b');
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (size(*a) == 2 && !issorted(*a))
		swap(a, &b, 'a');
	else if (!issorted(*a) && size(*a) > 2)
	{
		while (!issorted(*a) && (size(*a) > 3))
			push(a, &b, 'b');
		sort3(a, &b);
		while (b)
		{
			putcost(a, &b);
			costbenefit(a, &b);
			push(&b, a, 'a');
		}
		while (p_min(*a) <= mid(*a) && p_min(*a) != 0)
			rotate(a, &b, 'a');
		while (p_min(*a) > mid(*a) && p_min(*a) != 0)
			reverse(a, &b, 'a');
	}
	clear(&b);
}
