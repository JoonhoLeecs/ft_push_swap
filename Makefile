CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_LIBFT = ./libft/
LIBFT = libft.a
SRC = ft_capx_to_field.c \
		ft_chr_to_field.c \
		ft_chrs_to_field.c \
		ft_clear_field.c \
		ft_convert_format.c \
		ft_di_to_field.c \
		ft_lstiter_strlensum.c \
		ft_new_fieldnode_free.c \
		ft_newfield.c \
		ft_printf.c \
		ft_ptraddress_to_field.c \
		ft_str_to_field.c \
		ft_str_to_fieldlst.c \
		ft_terminate_on_error.c \
		ft_u_to_field.c \
		ft_ulltostr_base.c \
		ft_x_to_field.c \
		ft_convert_empty_str.c \
		ft_print_fields.c

OBJECTS = $(SRC:.c=.o)
NAME = libftprintf.a

.PHONY: all bonus clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : make_all

make_all : $(LIBFT) $(OBJECTS)
			$(AR) rcs $(NAME) $(OBJECTS)
			@touch make_all

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
