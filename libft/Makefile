CC		=	gcc

SHELL	:= /bin/bash

RED		= \033[1;31m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
ORANGE	= \033[1;38;5;214m
GREEN	= \033[1;32m
RESET	= \033[0m
UP1		= \033[1F
BEGIN	= \033[0G
SAVE	= \0337
RESTORE	= \0338
INSET	= $(BEGIN)$(GREEN)+ $(BLUE)

SRCS	=	$(SRC_ARRAY) $(SRC_ASCII) $(SRC_CONVERT) $(SRC_GNL)\
			$(SRC_LST) $(SRC_MEM) $(SRC_MISC) $(SRC_PRINTF)\
			$(SRC_PUT) $(SRC_STR)

SRC_ARRAY	=	array/ft_2darlen.c

SRC_ASCII	=	ascii/ft_isalnum.c \
				ascii/ft_isalpha.c \
				ascii/ft_isascii.c \
				ascii/ft_isdigit.c \
				ascii/ft_isprint.c \
				ascii/ft_iswhitespace.c

SRC_CONVERT	=	convert/ft_atoi.c \
				convert/ft_hextoi.c \
				convert/ft_itoa.c \
				convert/ft_tolower.c \
				convert/ft_toupper.c

SRC_GNL		=	gnl/get_next_line.c \
				gnl/get_next_line_utils.c

SRC_LST		=	lst/ft_lstadd_back.c \
				lst/ft_lstadd_front.c \
				lst/ft_lstclear.c \
				lst/ft_lstdelone.c \
				lst/ft_lstiter.c \
				lst/ft_lstlast.c \
				lst/ft_lstmap.c \
				lst/ft_lstnew.c \
				lst/ft_lstsize.c \

SRC_MEM		=	mem/ft_bzero.c \
				mem/ft_calloc.c \
				mem/ft_memchr.c \
				mem/ft_memcmp.c \
				mem/ft_memcpy.c \
				mem/ft_memmove.c \
				mem/ft_memset.c

SRC_MISC	=	misc/ft_abs.c \
				misc/ft_numlen.c

SRC_PRINTF	=	printf/ft_printchar.c \
				printf/ft_printf.c \
				printf/ft_printhex.c \
				printf/ft_printnbr.c \
				printf/ft_printstr.c \
				printf/ft_printun.c \
				printf/ft_upprinthex.c

SRC_PUT		=	put/ft_putchar_fd.c \
				put/ft_putendl_fd.c \
				put/ft_putnbr_fd.c \
				put/ft_putstr_fd.c

SRC_STR		=	str/ft_split.c \
				str/ft_strchr.c \
				str/ft_strdup.c \
				str/ft_striteri.c \
				str/ft_strjoin_free.c \
				str/ft_strjoin.c \
				str/ft_strlcat.c \
				str/ft_strlcpy.c \
				str/ft_strlen.c \
				str/ft_strmapi.c \
				str/ft_strncmp.c \
				str/ft_strnstr.c \
				str/ft_strrchr.c \
				str/ft_strtrim.c \
				str/ft_substr.c

INC			=	-I ./include

COMPILED	=	0

DONE_OBJS	=	$(wildcard obj/*.o)

TO_COMPILE	=	$(words $(filter-out $(DONE_OBJS), $(OBJS)))

PERCENT		=	$(INSET)$(CYAN)$(shell echo \
				$$(($(COMPILED)*100/$(TO_COMPILE)))%%)

ifeq ($(TESTFLAGS), 1)
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
else
CFLAGS	= -Wall -Wextra -Werror
endif

NAME	= libft.a

OBJS	= $(patsubst %.c, obj/%.o, $(SRCS))

all: heading status comp

.PHONY: heading status comp clean fclean re

comp: $(NAME)

heading:
	@printf "$(CYAN)---< $(ORANGE)Duco's libft $(CYAN)>---\n$(RESET)"

status:
ifneq ($(filter $(OBJS), $(wildcard obj/*/*.o)),)
	@printf "$(INSET)Nothing to be done.\n$(RESET)"
endif

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@
	@printf "$(PERCENT) $(BLUE)Compiling: $(GREEN)%s$(RESET)\n" "$^"
	$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))

$(NAME): $(OBJS)
	@printf "$(INSET)"
	@ar rcs $(NAME) $(OBJS)
	@printf "$(ORANGE)Created archive.\n$(RESET)"

clean: heading
	@rm -rf obj
	@printf "$(RED)- $(BLUE)Removed object files\n$(RESET)"

fclean: clean
	@rm -f libft.a
	@printf "$(RED)- $(BLUE)Removed archive file\n$(RESET)"

re: fclean comp
