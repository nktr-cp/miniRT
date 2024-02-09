# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 17:19:47 by misargsy          #+#    #+#              #
#    Updated: 2023/12/21 15:44:56 by misargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -I. -Iincludes
LIBFT =		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strcat.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strcmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

GNL = 		get_next_line_utils.c \
			get_next_line.c

PRINTF =	ft_printf.c \
			printf_get_format.c \
			print_int.c \
			print_uint.c \
			print_csp.c \
			print_hex.c \
			printf_utils.c

NAME = libft.a

GRAY		= \033[1;37m
CYAN		= \033[1;36m
MAGENTA		= \033[1;35m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
GREEN		= \033[1;32m
RED			= \033[1;31m
RESET		= \033[0m
MAX			= 50
CONVERSION	= %-$(MAX).$(MAX)s\r

SRCSDIR = srcs
OBJSDIR = objs
SRCS = $(patsubst %.c, $(SRCSDIR)/%.c, $(LIBFT) $(GNL) $(PRINTF))
OBJS = $(patsubst %.c, $(OBJSDIR)/%.o, $(LIBFT) $(GNL) $(PRINTF))

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(YELLOW)Compiling $@... $(CONVERSION)$(RESET)"
	@$(AR) -rc $(NAME) $(OBJS)
	@printf "$(GREEN)⪼ $(NAME): compilation done ⪻$(CONVERSION)$(RESET)\n"

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	@printf "$(MAGENTA)Compiling $@... $(CONVERSION)$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJSDIR)
	@$(RM) $(OBJS)
	@printf "$(RED)Removed $(NAME)'s object files$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Removed $(NAME)$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
