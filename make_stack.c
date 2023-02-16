/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdosso-d <pdosso-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:25:47 by pdosso-d          #+#    #+#             */
/*   Updated: 2023/02/16 15:27:22 by pdosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back_nb(t_stack *stack, t_stack *new)
{
	t_stack	*nb;

	nb = stack;
	if (!stack)
	{
		nb = new;
		return ;
	}
	while (nb->next)
		nb = nb->next;
	nb->next = new;
	new->next = NULL;
}

t_stack	*new_nb(int value)
{
	t_stack	*nb;

	nb = malloc(sizeof(t_stack));
	if (!nb)
		return (NULL);
	nb->value = value;
	nb->next = NULL;
	return (nb);
}

int	check_nb(t_stack *stack, int check_value, t_data *data)
{
	t_stack	*nb;

	nb = stack;
	while (nb)
	{
		if (nb->value == check_value)
		{
			if (data->err == 1)
				return (1);
			data->err = 1;
		}
		nb = nb->next;
	}
	return (0);
}

int	check_double(t_data *data)
{
	t_stack	*nb;

	nb = data->stack_a;
	while (nb)
	{
		if (check_nb(data->stack_a, nb->value, data) == 1)
			return (1);
		data->err = 0;
		nb = nb->next;
	}
	return (0);
}

int	make_stack(t_data *data, char **argv)
{
	int		i;
	t_stack	*nb;

	i = 0;
	data->stack_a = new_nb(ft_atoi(argv[++i]));
	if (!data->stack_a)
		return (ft_printf("Error of Alloc"));
	while (i < data->len)
	{
		nb = new_nb(ft_atoi(argv[++i]));
		if (!data->stack_a)
			return (ft_printf("Error of Alloc"));
		add_back_nb(data->stack_a, nb);
	}
	if (check_double(data) == 1)
		return (ft_printf("Duplicate Detected"));
	return (0);
}
