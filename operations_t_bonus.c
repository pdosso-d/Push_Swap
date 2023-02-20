/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_t_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdosso-d <pdosso-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:08:53 by pdosso-d          #+#    #+#             */
/*   Updated: 2023/02/16 21:03:42 by pdosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	t_stack	*nb_a;
	t_stack	*swap;

	nb_a = data->stack_a;
	while (nb_a->next->next)
		nb_a = nb_a->next;
	swap = new_nb(nb_a->next->value);
	free(nb_a->next);
	nb_a->next = NULL;
	nb_a = data->stack_a;
	swap->next = nb_a;
	data->stack_a = swap;
}

void	rrb(t_data *data)
{
	t_stack	*nb_b;
	t_stack	*swap;

	nb_b = data->stack_b;
	if (!nb_b || !nb_b->next)
		return ;
	while (nb_b->next->next)
		nb_b = nb_b->next;
	swap = new_nb(nb_b->next->value);
	free(nb_b->next);
	nb_b->next = NULL;
	nb_b = data->stack_b;
	swap->next = nb_b;
	data->stack_b = swap;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
