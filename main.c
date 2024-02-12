/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:08:26 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/11 10:31:42 by beredzhe         ###   ########.fr       */
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
	}
	return (4);
}