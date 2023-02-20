/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdosso-d <pdosso-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:26:04 by pdosso-d          #+#    #+#             */
/*   Updated: 2023/02/20 20:25:32 by pdosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sort(t_data *data)
{
	if (data->len == 4)
	{
		pb(data);
		sort_three_numbers(data);
		sort_stack(data);
	}
	else if (data->len < 3)
	{
		if (data->len == 2 && data->stack_a->value > data->stack_a->next->value)
			ra(data);
	}
	else
	{
		sort_median(data);
		sort_stack(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a = NULL;
		data.stack_b = NULL;
		data.len = argc - 1;
		data.err = 0;
		if (make_stack(&data, argv) > 0)
			return (1);
		make_sort(&data);
		free_stacks(&data);
	}
	else
		printf("wrong parameter");
}
