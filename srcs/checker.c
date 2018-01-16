/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:33:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/16 16:28:14 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int				get_numbers(t_stack **a, int argc, char **argv)
{
	long long int	temp;
	int				i;
	t_stack			*t;

	init_list(a, argc, argv);
	i = 1;
	t = *a;
	while (i < argc)
	{
		temp = (long long int)ft_atoi(argv[i]);
		if (!(check_valid_nb(temp, *a)))
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
	return (1);
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
	while (i < argc - 1)
	{
		if (!(new = ft_stacknew(0)))
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

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = ft_stacknew(0);
		line = NULL;
		if (get_numbers(&a, argc, argv))
		{
			do_operations(line, &a, &b);
		}
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (check_sort(a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		//ft_stackfree(&a);
		//ft_stackfree(&b);
	}
	else
		ft_printf("usage: ./checker -[options] numbers list (n1 n2...)\n");
	return (0);
}
