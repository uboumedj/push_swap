/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:33:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/16 02:54:13 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int						get_numbers(t_stack *a, int argc, char **argv)
{
	long long int	temp;
	int						i;
	t_stack				*t;

	init_list(a, argc, argv);
	i = 1;
	while (i < argc)
	{
		temp = (long long int)ft_atoi(argv[i]);
		if(!(check_valid_nb(temp)))
		{
			ft_printf("Error\n");
			exit(1);
		}
		else
		{
			t->content = temp;
			t = t->next;
		}
		i++;
	}
}

static int		init_list(t_stack *a, int argc, char **argv)
{
	t_stack *temp;
	int			i;

	if (!(check_valid_args(argc, argv)))
	{
		ft_printf("Error\n");
		exit(1);
	}
	i = 1;
	temp = a;
	while (i < argc)
	{
		if (!(temp->next = (t_list *)malloc(sizeof(t_list))))
		{
			ft_printf("Error\n");
			exit(1);
		}
		temp = temp->next;
		i++;
	}
}

int						main(int argc, char **argv)
{
  t_stack *a;
  t_stack *b;
  char    *line;

  if (argc > 1)
  {
    line = NULL;
    if (get_numbers(a, argc, argv))
      do_operations(line, a, b);
    else
    {
      ft_printf("Error\n");
      exit(1);
    }
    if (check_sort(a))
      ft_printf("OK\n");
    else
      ft_printf("KO\n");
  }
  else
    ft_printf("usage: ./checker -[options] numbers list (n1 n2...) op list\n");
  return (0);
}
