/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:54:54 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:12:33 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** after initializing the stack, get_numbers will put each number to be sorted
** inside it, all the while checking if there is an invalid number. If so, the
** program will exit with an error.
*/

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
		temp = ft_atoll(argv[i]);
		if (!(check_valid_nb(temp, t, *a)))
			mult_error(a, argv);
		else
		{
			(*a)->content = (int)temp;
			(*a) = (*a)->next;
		}
		i++;
	}
	i--;
	*a = t;
}

/*
** init_list initializes the first stack by creating the number of elements
** necessary to contain each number to be sorted.
*/

void			init_list(t_stack **a, int argc, char **argv)
{
	t_stack		*temp;
	t_stack		*new;
	int			i;

	if (!(check_valid_args(argc, argv)))
		mult_error(a, argv);
	i = 1;
	temp = *a;
	while (i < argc)
	{
		if (!(new = (t_stack *)malloc(sizeof(t_stack))))
			cmn_error();
		new->next = temp;
		temp = new;
		i++;
	}
	*a = temp;
}
