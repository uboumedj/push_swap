/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:43:43 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:16:49 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include "../libft/inc/libft.h"

typedef struct		s_data
{
	int				min_index;
	int				place;
	int				min_steps;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
}					t_data;

typedef struct		s_flags
{
	char			count;
	int				nb;
	char			v;
}					t_flags;

/*
** ----------------------Stack manipulation functions-----------------------
*/

void				sa(t_stack **a, t_stack **b, t_flags **flags);
void				sb(t_stack **a, t_stack **b, t_flags **flags);
void				ss(t_stack **a, t_stack **b, t_flags **flags);

void				pa(t_stack **a, t_stack **b, t_flags **flags);
void				pb(t_stack **a, t_stack **b, t_flags **flags);

void				ra(t_stack **a, t_stack **b, t_flags **flags);
void				rb(t_stack **a, t_stack **b, t_flags **flags);
void				rr(t_stack **a, t_stack **b, t_flags **flags);

void				rra(t_stack **a, t_stack **b, t_flags **flags);
void				rrb(t_stack **a, t_stack **b, t_flags **flags);
void				rrr(t_stack **a, t_stack **b, t_flags **flags);

/*
** -------------------------Common functions--------------------------------
*/

void				get_numbers(t_stack **a, int argc, char **argv);
void				init_list(t_stack **a, int argc, char **argv);
int					check_valid_nb(long long int nb, t_stack *t, t_stack *a);
int					check_valid_args(int argc, char **argv);
void				display_stacks(t_stack *a, t_stack *b);
void				strsplitfree(char **str);
int					check_for_flags(char **str, t_flags **flags);
void				do_flags(t_stack *a, t_stack *b, t_flags **flags);
void				do_count(t_flags *flags);
void				freedom(t_stack *a, t_stack *b, t_flags *flags, char **args);

/*
** -----------------------------Push_swap-----------------------------------
*/

int					min_val(t_stack *a);
int					max_val(t_stack *a);
int					last_val(t_stack *b);
int					min_index(t_stack *a);
int					stack_len(t_stack *a);
void				solve(t_stack **a, t_stack **b, t_flags **flags);
void				solve_three(t_stack **a, t_stack **b, t_flags **flags);
void				solve_small_len(t_stack **a, t_stack **b, t_flags **flags);
void				solve_big_len(t_stack **a, t_stack **b, t_flags **flags);
void				rotations(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
int					steps(int index, t_stack *a, t_stack *b);
void				min_steps(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
int					check_location(t_stack *b, int elem);
int					find_place(t_stack *a, t_stack *b, int index);
void				rot(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
void				revrot(t_stack **a, t_stack **b, t_data *data, t_flags **flags);
int					max_index(t_stack *a);
void				order_b(t_stack **a, t_stack **b, t_flags **flags);
void				push_back_to_a(t_stack **a, t_stack **b, t_flags **flags);

/*
** ------------------------------Checker------------------------------------
*/

int					check_sort(t_stack *a);
void				do_operations(char *line, t_stack **a, t_stack **b, t_flags **flags);

/*
** --------------------------------Errors------------------------------------
*/

void				cmn_error();
void				inst_error(t_stack **a, t_stack **b, char *line, t_flags **flags);
void				mult_error(t_stack **a, char **args);

#endif
