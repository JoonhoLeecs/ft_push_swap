CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_LIBFT = ./libft/
LIBFT = libft.a
SRC = assign_subs.c \
		divide_subs.c \
		divide_subs2.c \
		divide_subs3.c \
		merge_all.c \
		merge_all2.c \
		merge_all3.c \
		merge_all4.c \
		merge_all5.c \
		merge_all6.c \
		parse_input.c \
		ps_deck.c \
		ps_deck2.c \
		ps_ops.c \
		ps_ops2.c \
		ps_papb.c \
		ps_rr.c \
		ps_rrr.c \
		ps_ss.c \
		ps_sub_ops.c \
		ps_sub_ops2.c \
		ps_subseq.c \
		ps_subseq2.c \
		push_swap.c \
		refine_subs.c \
		sort_record.c \
		sort_small.c \
		sort_small2.c \
		strs_to_deck.c \
		refine_ops.c \
		refine_ops2.c \
		ft_strcmp.c
HEADER = push_swap.h
OBJECTS = $(SRC:.c=.o)
NAME = push_swap

.PHONY: all clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJECTS) $(HEADER)
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
