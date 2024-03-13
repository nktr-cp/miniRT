# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 19:08:43 by misargsy          #+#    #+#              #
#    Updated: 2024/03/13 21:55:27 by misargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I libft -I includes -fsanitize=address
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

SRCSDIR = srcs
OBJSDIR = objs

##############################################################################
MAIN =		main.c
MAIN :=		$(addprefix main/, $(MAIN))

OBJLIST =	objlistmanip.c
OBJLIST :=	$(addprefix objlist/, $(OBJLIST))

PARSE =		parse.c \
			parse_util.c \
			parse_env.c
PARSE :=	$(addprefix parse/, $(PARSE))

VECTOR =	basic_ops.c \
			cross.c \
			prod.c \
			norm.c
VECTOR :=	$(addprefix vector/, $(VECTOR))

UTILS =		exit.c \
			free.c
UTILS :=	$(addprefix utils/, $(UTILS))
##############################################################################

SRCS =	$(MAIN) $(OBJLIST) $(PARSE) $(VECTOR) $(UTILS)
SRCS :=	$(addprefix $(SRCSDIR)/, $(SRCS))
OBJS =	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@printf "$(YELLOW)Compiling $@... $(CONVERSION)$(RESET)"
	@$(CC) $(CFLAGS) $(MLXF) $(OBJS) -o $(NAME) $(LIBFT)
	@printf "$(GREEN)⪼ $(NAME): compilation done ⪻$(CONVERSION)$(RESET)\n"

$(LIBFT):
	@make -C libft
	@cp $(LIBFTDIR)/$(LIBFT) .

$(MLX):
	@make -C minilibx
	@cp $(MLXDIR)/$(MLX) .

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR) $(dir $@)
	@printf "$(MAGENTA)Compiling $@... $(CONVERSION)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

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
