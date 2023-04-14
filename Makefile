CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_LIBFT = ./libft/
LIBFT = libft.a
SRC = assign_subs.c \
		divide_subs.c \
		parse_input.c \
		ps_deck_add.c \
		ps_deck_remove.c \
		ps_deck.c \
		ps_ops_add.c \
		ps_ops.c \
		ps_papb.c \
		ps_rr.c \
		ps_rrr.c \
		ps_sort_record.c \
		ps_ss.c \
		ps_sub_ops.c \
		ps_subseq.c \
		ps_subseq2.c \
		push_swap.c \
		merge_all.c \
		sort_small.c \
		sort_small2.c \
		strs_to_deck.c

OBJECTS = $(SRC:.c=.o)
NAME = push_swap

.PHONY: all bonus clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L. -lft

# -g3 -fsanitize=address

$(LIBFT) :
	$(MAKE) bonus -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(NAME)

clean :
	$(MAKE) clean -C $(DIR_LIBFT)
	rm -f $(OBJECTS)
	rm -f $(LIBFT)
	rm -f make_all

fclean :
	$(MAKE) clean
	cd $(DIR_LIBFT); $(MAKE) fclean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all
