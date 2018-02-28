/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:43:43 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 14:23:14 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef struct		s_data
{
	int				*maxthree;
	int				min_index;
	int				place;
	int				min_steps;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
}					t_data;

/*
** ----------------------Pile manipulation functions------------------------
*/

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/*
** -------------------------Common functions--------------------------------
*/

void				get_numbers(t_stack **a, int argc, char **argv);
void				init_list(t_stack **a, int argc, char **argv);
int					check_valid_nb(long long int nb, t_stack *t, t_stack *a);
int					check_valid_args(int argc, char **argv);
void				display_stacks(t_stack *a, t_stack *b);

/*
** -----------------------------Push_swap-----------------------------------
*/

int					min_val(t_stack *a);
int					max_val(t_stack *a);
int					last_val(t_stack *b);
int					min_index(t_stack *a);
int					med_val(t_stack *a);
int					stack_len(t_stack *a);
int					*three_max(t_stack *a);
void				solve(t_stack **a, t_stack **b);
void				solve_three(t_stack **a);
void				solve_small_len(t_stack **a, t_stack **b);
void				solve_big_len(t_stack **a, t_stack **b);
void				rotations(t_stack **a, t_stack **b, t_data *data);
int					steps(int index, t_stack *a, t_stack *b, t_data *data);
void				min_steps(t_stack **a, t_stack **b, t_data *data);
int					check_location(t_stack *b, int elem);
int					find_place(t_stack *a, t_stack *b, int index, t_data *data);
void				rot(t_stack **a, t_stack **b, t_data *data);
void				revrot(t_stack **a, t_stack **b, t_data *data);
int					max_index(t_stack *a);
void				push_back_to_a(t_stack **a, t_stack **b);

/*
** ------------------------------Checker------------------------------------
*/

int					check_sort(t_stack *a);
void				do_operations(char *line, t_stack **a, t_stack **b);

/*
** --------------------------------Errors------------------------------------
*/

void				mem_error();
void				cmn_error();

#endif
