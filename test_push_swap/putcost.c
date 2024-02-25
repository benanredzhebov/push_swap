#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				data;
	int				cost;
	struct s_node	*next;
}	t_node;

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

int size(t_node *head) {
	t_node *tmp = head;
	int i = 0;
	while (tmp) {
		i++;
		tmp = tmp->next;
	}
	return i;
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

void	rotate1(t_node **a, t_node **b, char c)
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
	if (c == 'r')
		rotate1(b, a, 'c');
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

int	mid(t_node *head)
{
	return (size(head) / 2);
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

void    insert_end(int x, t_node **head)
{
    t_node    *new;
    t_node    *tmp;

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

void    duplicate(t_node *a, t_node *b, t_node **new, t_node **new2)
{
    t_node    *tmp;

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

void    reverse1(t_node **a, t_node **b, char c)
{
    t_node    *tmp;
    t_node    *tmp1;
    t_node    *tmp2;

    tmp = *a;
    tmp1 = tmp;
    while (tmp1->next->next)
        tmp1 = tmp1->next;
    tmp2 = tmp1->next;
    tmp2->next = tmp;
    tmp1->next = NULL;
    *a = tmp2;
    if (c == 'R')
        reverse1(b, a, 'c');
}

void    cost_div2(t_node **a, t_node **b, t_node **x, int *i)
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

void    cost_div1(t_node **a, t_node **b, t_node **x, int *i)
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


int    cost(t_node *head_a, t_node *head_b, t_node *x)
{
    int        i;
    t_node    *a;
    t_node    *b;

    i = 0;
    a = NULL;
    b = NULL;
    duplicate(head_a, head_b, &a, &b);
    cost_div1(&a, &b, &x, &i);
    cost_div2(&a, &b, &x, &i);
    clear(&a);
    clear(&b);
    return (i);
}

void putcost(t_node **head_a, t_node **head_b) {
    t_node *tmp;

    tmp = *head_b;
    while (tmp) {
        tmp->cost = cost(*head_a, *head_b, tmp);
        tmp = tmp->next;
    }
}

int main() {
	// Create sample linked lists
	t_node *head_a = malloc(sizeof(t_node));
	t_node *head_b = malloc(sizeof(t_node));
	head_a->data = 1;
	head_b->data = 2;
	head_a->next = NULL;
	head_b->next = NULL;

	t_node *node_a2 = malloc(sizeof(t_node));
	t_node *node_b2 = malloc(sizeof(t_node));
	node_a2->data = 3;
	node_b2->data = 4;
	node_a2->next = NULL;
	node_b2->next = NULL;
	head_a->next = node_a2;
	head_b->next = node_b2;

	// Call putcost function to calculate costs for each node in list b
	putcost(&head_a, &head_b);

	// Print the costs of nodes in list b
	t_node *tmp = head_b;
	while (tmp) {
		printf("Cost for node with data %d: %d\n", tmp->data, tmp->cost);
		tmp = tmp->next;
	}

	// Free allocated memory
	free(node_a2);
	free(node_b2);
	free(head_a);
	free(head_b);

	return 0;
}
