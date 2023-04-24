CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_LIBFT = ./libft/
LIBFT = libft.a
SRC = assign_subs.c \
		divide_subs.c \
		divide_subs2.c \
		divide_subs3.c \
		divide_subs4.c \
		divide_subs5.c \
		merge_all.c \
		merge_all2.c \
		merge_all3.c \
		parse_input.c \
		ps_deque.c \
		ps_deque2.c \
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
		strs_to_deque.c \
		refine_ops.c \
		refine_ops2.c \
		refine_ops3.c \
		ft_strcmp.c
SRC_BONUS = push_swap_bonus.c \
		parse_input_bonus.c \
		strs_to_deque_bonus.c \
		do_instruction_bonus.c \
		ps_deque_bonus.c \
		ps_deque2_bonus.c \
		psb_ppss_bonus.c \
		psb_rr_bonus.c \
		psb_rrr_bonus.c \
		ft_strcmp_bonus.c \
		getnextline/get_next_line.c \
		getnextline/get_next_line_utils.c
OBJECTS = $(SRC:.c=.o)
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)
HEADER = push_swap.h
HEADER_BONUS = push_swap_bonus.h getnextline/get_next_line.h
NAME = push_swap
NAME_BONUS = checker

.PHONY: all bonus clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJECTS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L. -lft

$(LIBFT) :
	$(MAKE) bonus -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(LIBFT)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJECTS_BONUS) $(HEADER_BONUS)
			$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS) -L. -lft

clean :
	$(MAKE) clean -C $(DIR_LIBFT)
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	rm -f $(LIBFT)
	rm -f make_all

fclean :
	$(MAKE) clean
	cd $(DIR_LIBFT); $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re :
	$(MAKE) fclean
	$(MAKE) all
