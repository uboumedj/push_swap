/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:30:45 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/16 16:15:24 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int			check_valid_nb(long long int nb, t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	while (temp)
	{
		if (temp->content == (int)nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			check_valid_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
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

int			check_sort(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp->next)
	{
		if (!(check_valid_nb(temp->content, temp->next)))
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}