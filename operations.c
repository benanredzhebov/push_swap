/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:42:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:42:35 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **a, t_node **b, char c)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *a;
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	tmp1->next = tmp;
	*a = tmp1;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	if (c == 's')
	{
		swap(b, a, 'c');
		write(1, "ss\n", 3);
	}
}

void	push(t_node **a, t_node **b, char c)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *a;
	tmp1 = tmp->next;
	tmp->next = *b;
	*b = tmp;
	*a = tmp1;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_node **a, t_node **b, char c)
{
	t_node	*tmp;
	t_node	*tmp1;
	t_node	*tmp2;

	tmp = *a;
	tmp1 = tmp->next;
	tmp2 = tmp;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	*a = tmp1;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
	if (c == 'r')
	{
		rotate(b, a, 'c');
		write(1, "rr\n", 3);
	}
}

void	reverse(t_node **a, t_node **b, char c)
{
	t_node	*tmp;
	t_node	*tmp1;
	t_node	*tmp2;

	tmp = *a;
	tmp1 = tmp;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp2->next = tmp;
	tmp1->next = NULL;
	*a = tmp2;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	if (c == 'R')
	{
		reverse(b, a, 'c');
		write(1, "rrr\n", 4);
	}
}
