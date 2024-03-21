# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 19:08:43 by misargsy          #+#    #+#              #
#    Updated: 2024/03/22 00:00:44 by misargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I libft -I includes #-fsanitize=address,undefined
MLXF = -framework OpenGL -framework AppKit

NAME = miniRT
LIBFTDIR = libft
LIBFT = libft.a
MLXDIR = minilibx
MLX = libmlx.dylib

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
			parse_env.c \
			range_check.c
PARSE :=	$(addprefix parse/, $(PARSE))

RENDER	=		render.c \
			intersection.c \
			intersect_plane.c \
			intersect_sphere.c \
			intersect_cylinder.c \
			camera.c \
			tracing.c \
			getcolor.c \
			mlx_ops.c
RENDER :=		$(addprefix render/, $(RENDER))

VECTOR =	basic_ops.c \
			cross.c \
			dot.c \
			norm.c \
			normalize.c
VECTOR :=	$(addprefix vector/, $(VECTOR))

UTILS =		exit.c \
			free.c \
			color.c
UTILS :=	$(addprefix utils/, $(UTILS))
##############################################################################

SRCS =	$(MAIN) $(OBJLIST) $(PARSE) $(RENDER) $(VECTOR) $(UTILS)
SRCS :=	$(addprefix $(SRCSDIR)/, $(SRCS))
OBJS =	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@printf "$(YELLOW)Compiling $@... $(CONVERSION)$(RESET)"
	$(CC) $(CFLAGS) $(MLXF) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)
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
	@printf "$(RED)Removed $(NAME)$(RESET)\n"

re: fclean all

bonus:

.PHONY: all clean fclean re bonus
