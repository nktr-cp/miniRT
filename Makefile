# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 19:08:43 by misargsy          #+#    #+#              #
#    Updated: 2024/02/09 19:26:29 by misargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -I libft -fsanitize=address
MLXF = -framework OpenGL -framework AppKit

NAME = miniRT
LIBFTDIR = libft
LIBFT = libft.a
MLXDIR = minilibx
MLX = libmlx.a

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

FILES =	main.c \

SRCSDIR = srcs
OBJSDIR = objs
SRCS = $(patsubst %.c, $(SRCSDIR)/%.c, $(FILES))
OBJS = $(patsubst %.c, $(OBJSDIR)/%.o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@printf "$(YELLOW)Compiling $@... $(CONVERSION)$(RESET)"
	@$(CC) $(FLAGS) $(MLXF) $(OBJS) -o $(NAME) $(LIBFT)
	@printf "$(GREEN)⪼ $(NAME): compilation done ⪻$(CONVERSION)$(RESET)\n"

$(LIBFT):
	@make -C libft
	@cp $(LIBFTDIR)/$(LIBFT) .

$(MLX):
	@make -C minilibx
	@cp $(MLXDIR)/$(MLX) .

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	@printf "$(MAGENTA)Compiling $@... $(CONVERSION)$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJSDIR)
	@$(RM) $(OBJS)
	@make -C libft clean
	@make -C minilibx clean
	@printf "$(RED)Removed $(NAME)'s object files$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(MLX)
	@make -C libft fclean
	@make -C minilibx clean
	@printf "$(RED)Removed $(NAME)$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re