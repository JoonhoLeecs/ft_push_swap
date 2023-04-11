/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:51:57 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 19:40:09 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_ps_node
{
	int			raw;
	int			sub_ind;
	t_ps_node	*next;
	t_ps_node	*prev;
}				t_ps_node;

typedef struct s_ps_subseq
{
	int			sub_ind;
	int			n_node;
	t_ps_node	*top;
	t_ps_node	*bottom;
	t_ps_subseq	*next_sub;
	t_ps_subseq	*prev_sub;

}				t_ps_subseq;

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

void		push_swap(int argc, char **argv);
t_ps_deck	*parse_input(int argc, char **argv);
t_ps_deck	*strs_to_deck(char **nbrs);
int			ps_atoi(const char *str, int *check);
int			have_duplicate(t_ps_deck *a);


t_ps_node	*ps_new_node(int raw);
t_ps_deck	*ps_new_deck(void);
void		ps_add_top(t_ps_deck *deck, t_ps_node *new);
void		ps_add_bottom(t_ps_deck *deck, t_ps_node *new);
void		ps_clear_deck(t_ps_deck *deck);
void		ps_clear_subseq(t_ps_deck *deck);

#endif
