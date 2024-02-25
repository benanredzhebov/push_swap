/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:02 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/16 10:40:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	int				cost;
	struct s_node	*next;
}	t_node;

void	push(t_node **a, t_node **b, char c);
void	get_list(char **str, t_node **head);
void	insert_end(int x, t_node **head);
int		check_min(t_node *head, int min);
int		check_max(t_node *head, int max);
void	reverse(t_node **a, t_node **b, char c);
void	rotate(t_node **a, t_node **b, char c);
void	swap(t_node **a, t_node **b, char c);
void	push_swap(t_node **head);
int		ft_iscorrect(char **str);
int		isreverse(t_node *head);
void	ft_print(t_node **head);
int		issorted(t_node *head);
void	clear(t_node **head);
int		p_min(t_node *head);
int		p_max(t_node *head);
int		checks(char **str);
int		size(t_node *head);
int		mid(t_node *head);
int		min(t_node *head);
int		max(t_node *head);
int		extra_case(t_node *head);
void	putcost(t_node **head_a, t_node **head_b);
void	duplicate(t_node *a, t_node *b, t_node **new, t_node **new2);
void	costbenefit(t_node **a, t_node **b);
int		target(t_node *x, t_node *a);
int		n_pos(t_node *x, t_node *head);
int		last(t_node *head);
t_node	*choose(t_node **b);
int		cost(t_node *head_a, t_node *head_b, t_node *x);
void	cost_div2(t_node **a, t_node **b, t_node **x, int *i);
void	cost_div1(t_node **a, t_node **b, t_node **x, int *i);
void	rotate1(t_node **a, t_node **b, char c);
void	reverse1(t_node **a, t_node **b, char c);

#endif