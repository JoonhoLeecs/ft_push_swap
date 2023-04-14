/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:51:57 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 07:24:28 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_ps_node
{
	int					raw;
	int					sub_ind;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}						t_ps_node;

typedef struct s_ps_subseq
{
	int					sub_ind;
	int					n_node;
	int					divide;
	t_ps_node			*top;
	t_ps_node			*bottom;
	struct s_ps_subseq	*next_sub;
	struct s_ps_subseq	*prev_sub;

}						t_ps_subseq;

typedef struct s_ps_deck
{
	int			n_node;
	t_ps_node	*top;
	t_ps_node	*bottom;
	t_ps_node	*ref;
	int			n_subseq;
	t_ps_subseq	*top_sub;
	t_ps_subseq	*bottom_sub;
	t_ps_subseq	*ref_sub;
}				t_ps_deck;

typedef struct s_oplst
{
	char			op[5];
	struct s_oplst	*next;
	struct s_oplst	*prev;
}					t_oplst;

typedef struct s_ops_deck
{
	t_oplst	*head;
	t_oplst	*tail;
}			t_ops_deck;

int			main(int argc, char **argv);
t_ps_deck	*parse_input(int argc, char **argv);
t_ps_deck	*strs_to_deck(char **nbrs);
int			ps_atoi(const char *str, int *check);
int			have_duplicate(t_ps_deck *a);

t_ops_deck	*ps_sort_record(t_ps_deck *a, t_ps_deck *b);
int			is_ordered(t_ps_deck *a);
int			sort_small(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			sort_two_a(t_ps_deck *a, t_ops_deck *ops);
int			sort_two_b(t_ps_deck *b, t_ops_deck *ops);
int			sort_three_a(t_ps_deck *a, t_ops_deck *ops);
int			sort_three_b(t_ps_deck *b, t_ops_deck *ops);
int			sort_four(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			smerge_b_to_a(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			sort_five(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);

int			assign_subs(t_ps_deck *a);

int			divide_subs(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_reverse_ra(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);

int			merge_all(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			merge_b_to_a(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			merge_a_to_b(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
void		submerge_b_to_a(t_ps_deck *a, t_ps_deck *b);

int			ps_sub_ra(t_ps_deck *a, t_ops_deck *ops);
int			ps_sub_pb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_sub_pbrb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_sub_para(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);

int			ps_sa(t_ps_deck *a, t_ops_deck *ops);
int			ps_sb(t_ps_deck *b, t_ops_deck *ops);
int			ps_ss(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_pa(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_pb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_ra(t_ps_deck *a, t_ops_deck *ops);
int			ps_rb(t_ps_deck *b, t_ops_deck *ops);
int			ps_rr(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);
int			ps_rra(t_ps_deck *a, t_ops_deck *ops);
int			ps_rrb(t_ps_deck *b, t_ops_deck *ops);
int			ps_rrr(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops);

t_ps_node	*ps_new_node(int raw);
t_ps_deck	*ps_new_deck(void);
void		ps_add_top(t_ps_deck *deck, t_ps_node *new);
void		ps_add_bottom(t_ps_deck *deck, t_ps_node *new);
t_ps_node	*ps_remove_top(t_ps_deck *deck);
t_ps_node	*ps_remove_bottom(t_ps_deck *deck);
void		ps_clear_deck(t_ps_deck *deck);
void		ps_clear_subseq(t_ps_deck *deck);

t_ops_deck	*ps_new_ops_deck(void);
t_oplst		*ps_new_oplst(char *str);
void		ops_add_front(t_ops_deck *ops_deck, t_oplst *new);
void		ops_add_back(t_ops_deck *ops_deck, t_oplst *new);
void		ps_clear_oplst(t_oplst *oplst);
t_ops_deck	*ps_clear_ops_deck(t_ops_deck *ops_deck);
void		ps_print_ops(t_ops_deck *ops_deck);

t_ps_subseq	*sub_new(t_ps_node *top, t_ps_node *bottom, int n, int ind);
void		sub_add_top(t_ps_deck *a, t_ps_subseq *sub);
void		sub_add_bottom(t_ps_deck *a, t_ps_subseq *sub);
t_ps_subseq	*sub_remove_top(t_ps_deck *deck);
t_ps_subseq	*sub_remove_bottom(t_ps_deck *deck);
void		clear_sub(t_ps_subseq *a);

// the following functions are temporary to check variables in process
void	pstest_print_decks(t_ps_deck *a, t_ps_deck *b);
void	pstest_print_subs(t_ps_deck *a, t_ps_deck *b);

#endif
