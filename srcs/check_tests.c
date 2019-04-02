/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:30:45 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 16:24:36 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** check_valid_nb checks if the current number is a valid INT value, and if it
** was not already input by the user. The program exits if those conditions are
** not met.
*/

int			check_valid_nb(long long int nb, t_stack *t, t_stack *a)
{
	t_stack	*temp;

	temp = t;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	while (temp != a)
	{
		if (temp->content == (int)nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*
** check_valid_args checks the program's parameters for invalid characters. The
** program accepts only digits (outside of the flags) so if this function
** detects any other character, the program will exit.
*/

int			check_valid_args(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** check_sort is a very useful function that checks if the number stack is
** already sorted. It is part of the basis of the algorithm's loop, checking at
** each turn if the first stack is sorted.
*/

int			check_sort(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
