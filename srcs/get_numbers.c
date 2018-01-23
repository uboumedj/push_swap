/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:54:54 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/23 14:18:36 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void			get_numbers(t_stack **a, int argc, char **argv)
{
	long long int	temp;
	int				i;
	t_stack			*t;

	init_list(a, argc, argv);
	i = 0;
	t = *a;
	while (i < argc)
	{
		temp = (long long int)ft_atoi(argv[i]);
		if (!(check_valid_nb(temp, t, *a)))
		{
			ft_printf("Error\n");
			exit(1);
		}
		else
		{
			(*a)->content = (int)temp;
			(*a) = (*a)->next;
		}
		i++;
	}
	*a = t;
}

void			init_list(t_stack **a, int argc, char **argv)
{
	t_stack		*temp;
	t_stack		*new;
	int			i;

	if (!(check_valid_args(argc, argv)))
	{
		ft_printf("Error\n");
		exit(1);
	}
	i = 1;
	temp = *a;
	while (i < argc)
	{
		if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		{
			ft_printf("Error\n");
			exit(1);
		}
		new->next = temp;
		temp = new;
		i++;
	}
	*a = temp;
}
