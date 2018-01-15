/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:33:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/15 23:33:59 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int						get_numbers(t_stack *a, int argc, char **argv)
{
	
}

static int		check_sort(t_stack *a)
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
    ft_printf("usage: ./checker -[options] numbers list (n1 n2 n3...)\n");
  return (0);
}
