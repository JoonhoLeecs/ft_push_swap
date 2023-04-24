/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:51:57 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/24 09:39:01 by joonhlee         ###   ########.fr       */
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

typedef struct s_ps_deque
{
	int			n_node;
	t_ps_node	*top;
	t_ps_node	*bottom;
	int			n_subseq;
	t_ps_subseq	*top_sub;
	t_ps_subseq	*bottom_sub;
}				t_ps_deque;

typedef struct s_op_node
{
	char				op[5];
	struct s_op_node	*next;
	struct s_op_node	*prev;
}						t_op_node;

typedef struct s_ops_deque
{
	t_op_node	*head;
	t_op_node	*tail;
}				t_ops_deque;

typedef struct s_ib_env
{
	long long	an_node;
	long long	bn_node;
	long long	an_sub;
	long long	bn_sub;
}				t_ib_env;

typedef struct s_m_env
{
	int	n_src_top;
	int	n_src_bot;
	int	n_dst_bot;
}		t_m_env;

int			main(int argc, char **argv);
t_ps_deque	*parse_input(int argc, char **argv);
int			valid_check(int argc, char **argv);
char		**arg_to_strs(int argc, char **argv);
char		*ft_strjoin_all(int argc, char **argv, char sep);
t_ps_deque	*strs_to_deque(char **nbrs);
int			ps_atoi(const char *str, int *check);
t_ps_deque	*free_nbrs_deque(char **nbrs, t_ps_deque *a);
int			have_duplicate(t_ps_deque *a);
t_ps_deque	*error_parse_input(void);

t_ops_deque	*sort_record(t_ps_deque *a, t_ps_deque *b);
int			is_ordered(t_ps_deque *a);
int			sort_small(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			sort_two_a(t_ps_deque *a, t_ops_deque *ops);
int			sort_two_b(t_ps_deque *b, t_ops_deque *ops);
int			sort_three_a(t_ps_deque *a, t_ops_deque *ops);
int			sort_three_b(t_ps_deque *b, t_ops_deque *ops);
int			sort_four(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			fmerge_b_to_a(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			sort_five(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			assign_subs(t_ps_deque *a);
int			find_next_inc_dec(t_ps_node *a);

int			divide_subs(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			move_seed(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			greatest_power_a(int n, unsigned int a);
int			move_seed_two(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			move_seed_s(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			move_seed_l(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int nf);
int			set_sign(int *sign, int nf);
int			find_sub_sign(t_ps_deque *a, int sign);
int			ds_move_s(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ds_move_l(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ds_realign(t_ps_deque *b, t_ops_deque *ops);
int			ds_find_rb_rrb(t_ps_deque *b);
int			same_order(t_ps_subseq *first, t_ps_subseq *second);

int			insertion_better(t_ps_deque *a, t_ps_deque *b);
long long	calc_next(t_ps_deque *a, t_ps_deque *b, t_ib_env *env);
int			insert_to_b(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			insert_rb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int s);
int			insert_rrb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int s);
int			raw_find_ra_rra(t_ps_deque *a, int raw);
int			move_rb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int raw);
int			move_rrb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int raw);
void		insert_submerge(t_ps_deque *b, t_ps_subseq *sub);
int			find_max(t_ps_deque *a);
int			find_min(t_ps_deque *a);

void		refine_subs(t_ps_deque *a, t_ps_deque *b);
void		refine_sub(t_ps_deque *a);
void		update_sub_ind(t_ps_subseq *sub, int sub_ind);

int			merge_all(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			merge_small(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			merge_allb_to_a(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			merge_alla_to_b(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			merge_a_to_b(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			mab(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			mabd(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			merge_b_to_a(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			mba(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			mbad(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
void		submerge_three_to_b(t_ps_deque *a, t_ps_deque *b);
void		submerge_tops_to_b(t_ps_deque *a, t_ps_deque *b);

void		refine_ops(t_ops_deque *ops);
int			is_op(t_op_node *op_node, char *op);
void		combine_to_rr(t_ops_deque *ops);
void		replace_to_rr(t_op_node *top, t_op_node *bottom, int ra, int rb);
void		combine_to_rrr(t_ops_deque *ops);
void		replace_to_rrr(t_op_node *top, t_op_node *bottom, int ra, int rb);
void		combine_to_ss(t_ops_deque *ops);
void		replace_to_ss(t_op_node *top, t_op_node *bottom, int ra, int rb);
t_op_node	*overwrite_n_op(t_op_node *start, char *op_str, int n);
int			ft_strcmp(char *s1, char *s2);
void		erase_ra_rra(t_ops_deque *ops);
void		erase_rb_rrb(t_ops_deque *ops);
void		erase_r_rr(t_op_node *top, t_op_node *bottom);

void		clear_all(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);

int			ps_sub_ra(t_ps_deque *a, t_ops_deque *ops);
int			ps_sub_rb(t_ps_deque *a, t_ops_deque *ops);
int			ps_sub_rra(t_ps_deque *a, t_ops_deque *ops);
int			ps_sub_rrb(t_ps_deque *b, t_ops_deque *ops);
int			ps_sub_pa(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_sub_pb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_sub_sa(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_sub_pbrb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_sub_para(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);

int			ps_sa(t_ps_deque *a, t_ops_deque *ops);
int			ps_sb(t_ps_deque *b, t_ops_deque *ops);
int			ps_ss(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_pa(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_pb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_ra(t_ps_deque *a, t_ops_deque *ops);
int			ps_rb(t_ps_deque *b, t_ops_deque *ops);
int			ps_rr(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_rra(t_ps_deque *a, t_ops_deque *ops);
int			ps_rrb(t_ps_deque *b, t_ops_deque *ops);
int			ps_rrr(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops);
int			ps_free_error(t_op_node *new);

t_ps_node	*ps_new_node(int raw);
t_ps_deque	*ps_new_deque(void);
void		ps_clear_deque(t_ps_deque *deque);
void		ps_clear_all_subseq(t_ps_deque *deque);
void		ps_add_top(t_ps_deque *deque, t_ps_node *new);
void		ps_add_bottom(t_ps_deque *deque, t_ps_node *new);
t_ps_node	*ps_remove_top(t_ps_deque *deque);
t_ps_node	*ps_remove_bottom(t_ps_deque *deque);

t_ops_deque	*ops_new_deque(void);
t_op_node	*ops_new_node(char *str);
void		ops_clear_node(t_op_node *op_node);
t_ops_deque	*ops_clear_deque(t_ops_deque *ops_deque);
void		ops_add_front(t_ops_deque *ops_deque, t_op_node *new);
void		ops_add_back(t_ops_deque *ops_deque, t_op_node *new);
void		ps_print_ops(t_ops_deque *ops_deque);

t_ps_subseq	*sub_new(t_ps_node *top, t_ps_node *bottom, int n, int ind);
void		sub_add_top(t_ps_deque *a, t_ps_subseq *sub);
void		sub_add_bottom(t_ps_deque *a, t_ps_subseq *sub);
t_ps_subseq	*sub_remove_top(t_ps_deque *deque);
t_ps_subseq	*sub_remove_bottom(t_ps_deque *deque);
void		clear_sub(t_ps_subseq *a);

#endif
