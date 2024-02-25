/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:42:21 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/23 11:42:21 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;

	head = NULL;
	if (argc > 1)
	{
		if (!checks(argv))
			return (2);
		get_list(argv, &head);
		if (extra_case(head))
			return (3);
		push_swap(&head);
		clear(&head);
		return (0);
	}
	return (4);
}
