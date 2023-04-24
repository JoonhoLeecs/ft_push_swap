/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:51:57 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/24 09:38:25 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "getnextline/get_next_line.h"

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
void		do_instruction(t_ps_deque *a, t_ps_deque *b);
int			is_valid_ins(char *ins);
void		move_node(char *ins, t_ps_deque *a, t_ps_deque *b);
int			print_error(void);
int			is_ordered(t_ps_deque *a);
int			ft_strcmp(char *s1, char *s2);
void		clear_all(t_ps_deque *a, t_ps_deque *b);

int			psb_sa(t_ps_deque *a);
int			psb_sb(t_ps_deque *b);
int			psb_ss(t_ps_deque *a, t_ps_deque *b);
int			psb_pa(t_ps_deque *a, t_ps_deque *b);
int			psb_pb(t_ps_deque *a, t_ps_deque *b);
int			psb_ra(t_ps_deque *a);
int			psb_rb(t_ps_deque *b);
int			psb_rr(t_ps_deque *a, t_ps_deque *b);
int			psb_rra(t_ps_deque *a);
int			psb_rrb(t_ps_deque *b);
int			psb_rrr(t_ps_deque *a, t_ps_deque *b);

t_ps_node	*ps_new_node(int raw);
t_ps_deque	*ps_new_deque(void);
void		ps_clear_deque(t_ps_deque *deque);
void		ps_clear_all_subseq(t_ps_deque *deque);
void		ps_add_top(t_ps_deque *deque, t_ps_node *new);
void		ps_add_bottom(t_ps_deque *deque, t_ps_node *new);
t_ps_node	*ps_remove_top(t_ps_deque *deque);
t_ps_node	*ps_remove_bottom(t_ps_deque *deque);

#endif
